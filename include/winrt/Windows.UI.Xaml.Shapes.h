#pragma once
// generated by isopod tools
// namespaces:
// Windows.UI.Xaml.Shapes

#include "Windows.UI.Xaml.Shapes.0.h"
#include "Windows.UI.Xaml.Media.0.h"
#include "Windows.UI.Xaml.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace UI { namespace Composition {
struct CompositionBrush;
}}}

// defs

template<> struct def<Windows::UI::Xaml::Shapes::IShape> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::IShapeStatics> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::IShapeFactory> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::IShape2> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::Shape> : class_type<Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2> {};
template<> struct def<Windows::UI::Xaml::Shapes::IEllipse> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::Ellipse> : class_type<Windows::UI::Xaml::Shapes::Shape, Windows::UI::Xaml::Shapes::IEllipse> {};
template<> struct def<Windows::UI::Xaml::Shapes::ILine> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::ILineStatics> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::Line> : class_type<Windows::UI::Xaml::Shapes::Shape, Windows::UI::Xaml::Shapes::ILine> {};
template<> struct def<Windows::UI::Xaml::Shapes::IPath> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::IPathStatics> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::IPathFactory> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::Path> : class_type<Windows::UI::Xaml::Shapes::Shape, Windows::UI::Xaml::Shapes::IPath>, composer_type<Windows::UI::Xaml::Shapes::IPathFactory> {};
template<> struct def<Windows::UI::Xaml::Shapes::IPolygon> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::IPolygonStatics> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::Polygon> : class_type<Windows::UI::Xaml::Shapes::Shape, Windows::UI::Xaml::Shapes::IPolygon> {};
template<> struct def<Windows::UI::Xaml::Shapes::IPolyline> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::IPolylineStatics> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::Polyline> : class_type<Windows::UI::Xaml::Shapes::Shape, Windows::UI::Xaml::Shapes::IPolyline> {};
template<> struct def<Windows::UI::Xaml::Shapes::IRectangle> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::IRectangleStatics> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Shapes::Rectangle> : class_type<Windows::UI::Xaml::Shapes::Shape, Windows::UI::Xaml::Shapes::IRectangle> {};

// uuids

template<> struct uuid<Windows::UI::Xaml::Shapes::IShape> { define_guid(0x786F2B75, 0x9AA0, 0x454D, 0xAE, 0x6, 0xA2, 0x46, 0x6E, 0x37, 0xC8, 0x32);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IShapeStatics> { define_guid(0x1D7B4C55, 0x9DF3, 0x48DC, 0x91, 0x94, 0x9D, 0x30, 0x6F, 0xAA, 0x60, 0x89);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IShapeFactory> { define_guid(0x4B717613, 0xF6AA, 0x48D5, 0x95, 0x88, 0xE1, 0xD1, 0x88, 0xEA, 0xCB, 0xC9);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IShape2> { define_guid(0x97248DBA, 0x49F2, 0x49A4, 0xA5, 0xDD, 0x16, 0x4D, 0xF8, 0x24, 0xDB, 0x14);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IEllipse> { define_guid(0x70E05AC4, 0xD38D, 0x4BAB, 0x83, 0x1F, 0x4A, 0x22, 0xEF, 0x52, 0xAC, 0x86);};
template<> struct uuid<Windows::UI::Xaml::Shapes::ILine> { define_guid(0x46A5433D, 0x4FFB, 0x48DF, 0x87, 0x32, 0x4E, 0x15, 0xC8, 0x34, 0x81, 0x6B);};
template<> struct uuid<Windows::UI::Xaml::Shapes::ILineStatics> { define_guid(0x267C123D, 0x6EA4, 0x4C50, 0x8B, 0x1D, 0x50, 0x20, 0x7A, 0xFF, 0x1E, 0x8A);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IPath> { define_guid(0x78883609, 0x3D57, 0x4F3C, 0xB8, 0xA5, 0x6C, 0xAB, 0xCA, 0xC9, 0x71, 0x1F);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IPathStatics> { define_guid(0xF627E59D, 0x87DC, 0x4142, 0x81, 0xF1, 0x97, 0xFC, 0x7F, 0xF8, 0x64, 0x1C);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IPathFactory> { define_guid(0x2340A4E3, 0x5A86, 0x4FC6, 0x9A, 0x50, 0xCB, 0xB9, 0x3B, 0x82, 0x87, 0x66);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IPolygon> { define_guid(0xE3755C19, 0x2E4D, 0x4BCC, 0x8D, 0x34, 0x86, 0x87, 0x19, 0x57, 0xFA, 0x1);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IPolygonStatics> { define_guid(0x362A8AAB, 0xD463, 0x4366, 0x9E, 0x1A, 0xBE, 0xBA, 0x72, 0x81, 0xF, 0xB7);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IPolyline> { define_guid(0x91DC62F8, 0x42B3, 0x47F3, 0x84, 0x76, 0xC5, 0x51, 0x24, 0xA7, 0xC4, 0xC6);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IPolylineStatics> { define_guid(0xC7AA2CD1, 0xA26C, 0x43B0, 0xAA, 0xA5, 0x82, 0x2F, 0xA6, 0x4A, 0x11, 0xB9);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IRectangle> { define_guid(0x855BC230, 0x8A11, 0x4E18, 0xA1, 0x36, 0x4B, 0xC2, 0x1C, 0x78, 0x27, 0xB0);};
template<> struct uuid<Windows::UI::Xaml::Shapes::IRectangleStatics> { define_guid(0x9F25AA53, 0xBB3A, 0x4C3C, 0x89, 0xDB, 0x6F, 0xBC, 0xD, 0x1F, 0xA0, 0xCC);};

// types

namespace Windows { namespace UI { namespace Xaml { namespace Shapes {

// IShape
struct IShape_raw : IInspectable {
	virtual STDMETHODIMP _get_Fill(Media::Brush* *value);
	virtual STDMETHODIMP _put_Fill(Media::Brush* value);
	virtual STDMETHODIMP _get_Stroke(Media::Brush* *value);
	virtual STDMETHODIMP _put_Stroke(Media::Brush* value);
	virtual STDMETHODIMP _get_StrokeMiterLimit(double *value);
	virtual STDMETHODIMP _put_StrokeMiterLimit(double value);
	virtual STDMETHODIMP _get_StrokeThickness(double *value);
	virtual STDMETHODIMP _put_StrokeThickness(double value);
	virtual STDMETHODIMP _get_StrokeStartLineCap(Media::PenLineCap *value);
	virtual STDMETHODIMP _put_StrokeStartLineCap(Media::PenLineCap value);
	virtual STDMETHODIMP _get_StrokeEndLineCap(Media::PenLineCap *value);
	virtual STDMETHODIMP _put_StrokeEndLineCap(Media::PenLineCap value);
	virtual STDMETHODIMP _get_StrokeLineJoin(Media::PenLineJoin *value);
	virtual STDMETHODIMP _put_StrokeLineJoin(Media::PenLineJoin value);
	virtual STDMETHODIMP _get_StrokeDashOffset(double *value);
	virtual STDMETHODIMP _put_StrokeDashOffset(double value);
	virtual STDMETHODIMP _get_StrokeDashCap(Media::PenLineCap *value);
	virtual STDMETHODIMP _put_StrokeDashCap(Media::PenLineCap value);
	virtual STDMETHODIMP _get_StrokeDashArray(Media::DoubleCollection* *value);
	virtual STDMETHODIMP _put_StrokeDashArray(Media::DoubleCollection* value);
	virtual STDMETHODIMP _get_Stretch(Media::Stretch *value);
	virtual STDMETHODIMP _put_Stretch(Media::Stretch value);
	virtual STDMETHODIMP _get_GeometryTransform(Media::Transform* *value);
};
template<typename X> struct IShape_adaptor : X {
	union {
		struct : property {
			ptr<Media::Brush> get() { Media::Brush* value; hrcheck(enc(&IShape_adaptor::Fill)->_get_Fill(&value)); return from_abi(value); }
			ptr<Media::Brush> operator()() { return get(); }
			operator ptr<Media::Brush> () { return get(); }
			ptr<Media::Brush> operator->() { return get(); }
			void put(pptr<Media::Brush> value) { hrcheck(enc(&IShape_adaptor::Fill)->_put_Fill(value)); }
			void operator=(pptr<Media::Brush> value) { put(value); }
			void operator()(pptr<Media::Brush> value) { put(value); }
		} Fill;
		struct : property {
			ptr<Media::Transform> get() { Media::Transform* value; hrcheck(enc(&IShape_adaptor::GeometryTransform)->_get_GeometryTransform(&value)); return from_abi(value); }
			ptr<Media::Transform> operator()() { return get(); }
			operator ptr<Media::Transform> () { return get(); }
			ptr<Media::Transform> operator->() { return get(); }
		} GeometryTransform;
		struct : property {
			Media::Stretch get() { Media::Stretch value; hrcheck(enc(&IShape_adaptor::Stretch)->_get_Stretch(&value)); return value; }
			Media::Stretch operator()() { return get(); }
			operator Media::Stretch () { return get(); }
			void put(Media::Stretch value) { hrcheck(enc(&IShape_adaptor::Stretch)->_put_Stretch(value)); }
			void operator=(Media::Stretch value) { put(value); }
			void operator()(Media::Stretch value) { put(value); }
		} Stretch;
		struct : property {
			ptr<Media::Brush> get() { Media::Brush* value; hrcheck(enc(&IShape_adaptor::Stroke)->_get_Stroke(&value)); return from_abi(value); }
			ptr<Media::Brush> operator()() { return get(); }
			operator ptr<Media::Brush> () { return get(); }
			ptr<Media::Brush> operator->() { return get(); }
			void put(pptr<Media::Brush> value) { hrcheck(enc(&IShape_adaptor::Stroke)->_put_Stroke(value)); }
			void operator=(pptr<Media::Brush> value) { put(value); }
			void operator()(pptr<Media::Brush> value) { put(value); }
		} Stroke;
		struct : property {
			ptr<Media::DoubleCollection> get() { Media::DoubleCollection* value; hrcheck(enc(&IShape_adaptor::StrokeDashArray)->_get_StrokeDashArray(&value)); return from_abi(value); }
			ptr<Media::DoubleCollection> operator()() { return get(); }
			operator ptr<Media::DoubleCollection> () { return get(); }
			ptr<Media::DoubleCollection> operator->() { return get(); }
			void put(pptr<Media::DoubleCollection> value) { hrcheck(enc(&IShape_adaptor::StrokeDashArray)->_put_StrokeDashArray(value)); }
			void operator=(pptr<Media::DoubleCollection> value) { put(value); }
			void operator()(pptr<Media::DoubleCollection> value) { put(value); }
		} StrokeDashArray;
		struct : property {
			Media::PenLineCap get() { Media::PenLineCap value; hrcheck(enc(&IShape_adaptor::StrokeDashCap)->_get_StrokeDashCap(&value)); return value; }
			Media::PenLineCap operator()() { return get(); }
			operator Media::PenLineCap () { return get(); }
			void put(Media::PenLineCap value) { hrcheck(enc(&IShape_adaptor::StrokeDashCap)->_put_StrokeDashCap(value)); }
			void operator=(Media::PenLineCap value) { put(value); }
			void operator()(Media::PenLineCap value) { put(value); }
		} StrokeDashCap;
		struct : property {
			double get() { double value; hrcheck(enc(&IShape_adaptor::StrokeDashOffset)->_get_StrokeDashOffset(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&IShape_adaptor::StrokeDashOffset)->_put_StrokeDashOffset(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} StrokeDashOffset;
		struct : property {
			Media::PenLineCap get() { Media::PenLineCap value; hrcheck(enc(&IShape_adaptor::StrokeEndLineCap)->_get_StrokeEndLineCap(&value)); return value; }
			Media::PenLineCap operator()() { return get(); }
			operator Media::PenLineCap () { return get(); }
			void put(Media::PenLineCap value) { hrcheck(enc(&IShape_adaptor::StrokeEndLineCap)->_put_StrokeEndLineCap(value)); }
			void operator=(Media::PenLineCap value) { put(value); }
			void operator()(Media::PenLineCap value) { put(value); }
		} StrokeEndLineCap;
		struct : property {
			Media::PenLineJoin get() { Media::PenLineJoin value; hrcheck(enc(&IShape_adaptor::StrokeLineJoin)->_get_StrokeLineJoin(&value)); return value; }
			Media::PenLineJoin operator()() { return get(); }
			operator Media::PenLineJoin () { return get(); }
			void put(Media::PenLineJoin value) { hrcheck(enc(&IShape_adaptor::StrokeLineJoin)->_put_StrokeLineJoin(value)); }
			void operator=(Media::PenLineJoin value) { put(value); }
			void operator()(Media::PenLineJoin value) { put(value); }
		} StrokeLineJoin;
		struct : property {
			double get() { double value; hrcheck(enc(&IShape_adaptor::StrokeMiterLimit)->_get_StrokeMiterLimit(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&IShape_adaptor::StrokeMiterLimit)->_put_StrokeMiterLimit(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} StrokeMiterLimit;
		struct : property {
			Media::PenLineCap get() { Media::PenLineCap value; hrcheck(enc(&IShape_adaptor::StrokeStartLineCap)->_get_StrokeStartLineCap(&value)); return value; }
			Media::PenLineCap operator()() { return get(); }
			operator Media::PenLineCap () { return get(); }
			void put(Media::PenLineCap value) { hrcheck(enc(&IShape_adaptor::StrokeStartLineCap)->_put_StrokeStartLineCap(value)); }
			void operator=(Media::PenLineCap value) { put(value); }
			void operator()(Media::PenLineCap value) { put(value); }
		} StrokeStartLineCap;
		struct : property {
			double get() { double value; hrcheck(enc(&IShape_adaptor::StrokeThickness)->_get_StrokeThickness(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&IShape_adaptor::StrokeThickness)->_put_StrokeThickness(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} StrokeThickness;
	};
	IShape_adaptor() {}
};
template<typename X> struct adapt<IShape, X> : Windows::UI::Xaml::Shapes::IShape_adaptor<X> { typedef adapt IShape; };
struct IShape : IShape_raw, generate<IShape> {};

// IShapeStatics
struct IShapeStatics : IInspectable {
	virtual STDMETHODIMP _get_FillProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_StrokeProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_StrokeMiterLimitProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_StrokeThicknessProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_StrokeStartLineCapProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_StrokeEndLineCapProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_StrokeLineJoinProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_StrokeDashOffsetProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_StrokeDashCapProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_StrokeDashArrayProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_StretchProperty(DependencyProperty* *value);
};

// IShapeFactory
struct IShapeFactory : IInspectable {
	virtual STDMETHODIMP _CreateInstance(IInspectable* outer, IInspectable* *inner, Shape* *instance);
};

// IShape2
struct IShape2_raw : IInspectable {
	virtual STDMETHODIMP _GetAlphaMask(Composition::CompositionBrush* *returnValue);
};
template<typename X> struct IShape2_adaptor : X {
	ptr<Composition::CompositionBrush> GetAlphaMask() { Composition::CompositionBrush* returnValue; hrcheck(X::get()->_GetAlphaMask(&returnValue)); return from_abi(returnValue); }
};
template<typename X> struct adapt<IShape2, X> : Windows::UI::Xaml::Shapes::IShape2_adaptor<X> { typedef adapt IShape2; };
struct IShape2 : IShape2_raw, generate<IShape2> {};

// Shape
template<typename> struct Shape_statics {
	static struct _FillProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_FillProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} FillProperty;
	static struct _StretchProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_StretchProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} StretchProperty;
	static struct _StrokeDashArrayProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_StrokeDashArrayProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} StrokeDashArrayProperty;
	static struct _StrokeDashCapProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_StrokeDashCapProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} StrokeDashCapProperty;
	static struct _StrokeDashOffsetProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_StrokeDashOffsetProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} StrokeDashOffsetProperty;
	static struct _StrokeEndLineCapProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_StrokeEndLineCapProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} StrokeEndLineCapProperty;
	static struct _StrokeLineJoinProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_StrokeLineJoinProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} StrokeLineJoinProperty;
	static struct _StrokeMiterLimitProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_StrokeMiterLimitProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} StrokeMiterLimitProperty;
	static struct _StrokeProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_StrokeProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} StrokeProperty;
	static struct _StrokeStartLineCapProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_StrokeStartLineCapProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} StrokeStartLineCapProperty;
	static struct _StrokeThicknessProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Shape, IShapeStatics>()->_get_StrokeThicknessProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} StrokeThicknessProperty;
};
template<typename X> typename Shape_statics<X>::_FillProperty Shape_statics<X>::FillProperty;
template<typename X> typename Shape_statics<X>::_StretchProperty Shape_statics<X>::StretchProperty;
template<typename X> typename Shape_statics<X>::_StrokeDashArrayProperty Shape_statics<X>::StrokeDashArrayProperty;
template<typename X> typename Shape_statics<X>::_StrokeDashCapProperty Shape_statics<X>::StrokeDashCapProperty;
template<typename X> typename Shape_statics<X>::_StrokeDashOffsetProperty Shape_statics<X>::StrokeDashOffsetProperty;
template<typename X> typename Shape_statics<X>::_StrokeEndLineCapProperty Shape_statics<X>::StrokeEndLineCapProperty;
template<typename X> typename Shape_statics<X>::_StrokeLineJoinProperty Shape_statics<X>::StrokeLineJoinProperty;
template<typename X> typename Shape_statics<X>::_StrokeMiterLimitProperty Shape_statics<X>::StrokeMiterLimitProperty;
template<typename X> typename Shape_statics<X>::_StrokeProperty Shape_statics<X>::StrokeProperty;
template<typename X> typename Shape_statics<X>::_StrokeStartLineCapProperty Shape_statics<X>::StrokeStartLineCapProperty;
template<typename X> typename Shape_statics<X>::_StrokeThicknessProperty Shape_statics<X>::StrokeThicknessProperty;

template<typename X> struct statics<Shape, X> : X, Windows::UI::Xaml::Shapes::Shape_statics<void> {
	typedef typename X::root_type Shape;
};
struct Shape : generate<Shape> {};

// IEllipse
struct IEllipse : IInspectable, generate<IEllipse> {};

// Ellipse
template<typename X> struct statics<Ellipse, X> : X {
	typedef typename X::root_type Ellipse;
};
struct Ellipse : generate<Ellipse> {};

// ILine
struct ILine_raw : IInspectable {
	virtual STDMETHODIMP _get_X1(double *value);
	virtual STDMETHODIMP _put_X1(double value);
	virtual STDMETHODIMP _get_Y1(double *value);
	virtual STDMETHODIMP _put_Y1(double value);
	virtual STDMETHODIMP _get_X2(double *value);
	virtual STDMETHODIMP _put_X2(double value);
	virtual STDMETHODIMP _get_Y2(double *value);
	virtual STDMETHODIMP _put_Y2(double value);
};
template<typename X> struct ILine_adaptor : X {
	union {
		struct : property {
			double get() { double value; hrcheck(enc(&ILine_adaptor::X1)->_get_X1(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&ILine_adaptor::X1)->_put_X1(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} X1;
		struct : property {
			double get() { double value; hrcheck(enc(&ILine_adaptor::X2)->_get_X2(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&ILine_adaptor::X2)->_put_X2(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} X2;
		struct : property {
			double get() { double value; hrcheck(enc(&ILine_adaptor::Y1)->_get_Y1(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&ILine_adaptor::Y1)->_put_Y1(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} Y1;
		struct : property {
			double get() { double value; hrcheck(enc(&ILine_adaptor::Y2)->_get_Y2(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&ILine_adaptor::Y2)->_put_Y2(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} Y2;
	};
	ILine_adaptor() {}
};
template<typename X> struct adapt<ILine, X> : Windows::UI::Xaml::Shapes::ILine_adaptor<X> { typedef adapt ILine; };
struct ILine : ILine_raw, generate<ILine> {};

// ILineStatics
struct ILineStatics : IInspectable {
	virtual STDMETHODIMP _get_X1Property(DependencyProperty* *value);
	virtual STDMETHODIMP _get_Y1Property(DependencyProperty* *value);
	virtual STDMETHODIMP _get_X2Property(DependencyProperty* *value);
	virtual STDMETHODIMP _get_Y2Property(DependencyProperty* *value);
};

// Line
template<typename> struct Line_statics {
	static struct _X1Property : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Line, ILineStatics>()->_get_X1Property(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} X1Property;
	static struct _X2Property : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Line, ILineStatics>()->_get_X2Property(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} X2Property;
	static struct _Y1Property : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Line, ILineStatics>()->_get_Y1Property(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} Y1Property;
	static struct _Y2Property : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Line, ILineStatics>()->_get_Y2Property(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} Y2Property;
};
template<typename X> typename Line_statics<X>::_X1Property Line_statics<X>::X1Property;
template<typename X> typename Line_statics<X>::_X2Property Line_statics<X>::X2Property;
template<typename X> typename Line_statics<X>::_Y1Property Line_statics<X>::Y1Property;
template<typename X> typename Line_statics<X>::_Y2Property Line_statics<X>::Y2Property;

template<typename X> struct statics<Line, X> : X, Windows::UI::Xaml::Shapes::Line_statics<void> {
	typedef typename X::root_type Line;
};
struct Line : generate<Line> {};

// IPath
struct IPath_raw : IInspectable {
	virtual STDMETHODIMP _get_Data(Media::Geometry* *value);
	virtual STDMETHODIMP _put_Data(Media::Geometry* value);
};
template<typename X> struct IPath_adaptor : X {
	union {
		struct : property {
			ptr<Media::Geometry> get() { Media::Geometry* value; hrcheck(enc(&IPath_adaptor::Data)->_get_Data(&value)); return from_abi(value); }
			ptr<Media::Geometry> operator()() { return get(); }
			operator ptr<Media::Geometry> () { return get(); }
			ptr<Media::Geometry> operator->() { return get(); }
			void put(pptr<Media::Geometry> value) { hrcheck(enc(&IPath_adaptor::Data)->_put_Data(value)); }
			void operator=(pptr<Media::Geometry> value) { put(value); }
			void operator()(pptr<Media::Geometry> value) { put(value); }
		} Data;
	};
	IPath_adaptor() {}
};
template<typename X> struct adapt<IPath, X> : Windows::UI::Xaml::Shapes::IPath_adaptor<X> { typedef adapt IPath; };
struct IPath : IPath_raw, generate<IPath> {};

// IPathStatics
struct IPathStatics : IInspectable {
	virtual STDMETHODIMP _get_DataProperty(DependencyProperty* *value);
};

// IPathFactory
struct IPathFactory : IInspectable {
	virtual STDMETHODIMP _CreateInstance(IInspectable* outer, IInspectable* *inner, Path* *instance);
};

// Path
template<typename> struct Path_statics {
	static struct _DataProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Path, IPathStatics>()->_get_DataProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} DataProperty;
	static Path *activate(object_ref outer, IInspectable* *inner) { Path *instance; hrcheck(get_activation_factory<Path, IPathFactory>()->_CreateInstance(outer, inner, &instance)); return instance; }
};
template<typename X> typename Path_statics<X>::_DataProperty Path_statics<X>::DataProperty;

template<typename X> struct statics<Path, X> : X, Windows::UI::Xaml::Shapes::Path_statics<void> {
	using Windows::UI::Xaml::Shapes::Path_statics<void>::activate;
	typedef typename X::root_type Path;
};
struct Path : generate<Path> {};

// IPolygon
struct IPolygon_raw : IInspectable {
	virtual STDMETHODIMP _get_FillRule(Media::FillRule *value);
	virtual STDMETHODIMP _put_FillRule(Media::FillRule value);
	virtual STDMETHODIMP _get_Points(Media::PointCollection* *value);
	virtual STDMETHODIMP _put_Points(Media::PointCollection* value);
};
template<typename X> struct IPolygon_adaptor : X {
	union {
		struct : property {
			Media::FillRule get() { Media::FillRule value; hrcheck(enc(&IPolygon_adaptor::FillRule)->_get_FillRule(&value)); return value; }
			Media::FillRule operator()() { return get(); }
			operator Media::FillRule () { return get(); }
			void put(Media::FillRule value) { hrcheck(enc(&IPolygon_adaptor::FillRule)->_put_FillRule(value)); }
			void operator=(Media::FillRule value) { put(value); }
			void operator()(Media::FillRule value) { put(value); }
		} FillRule;
		struct : property {
			ptr<Media::PointCollection> get() { Media::PointCollection* value; hrcheck(enc(&IPolygon_adaptor::Points)->_get_Points(&value)); return from_abi(value); }
			ptr<Media::PointCollection> operator()() { return get(); }
			operator ptr<Media::PointCollection> () { return get(); }
			ptr<Media::PointCollection> operator->() { return get(); }
			void put(pptr<Media::PointCollection> value) { hrcheck(enc(&IPolygon_adaptor::Points)->_put_Points(value)); }
			void operator=(pptr<Media::PointCollection> value) { put(value); }
			void operator()(pptr<Media::PointCollection> value) { put(value); }
		} Points;
	};
	IPolygon_adaptor() {}
};
template<typename X> struct adapt<IPolygon, X> : Windows::UI::Xaml::Shapes::IPolygon_adaptor<X> { typedef adapt IPolygon; };
struct IPolygon : IPolygon_raw, generate<IPolygon> {};

// IPolygonStatics
struct IPolygonStatics : IInspectable {
	virtual STDMETHODIMP _get_FillRuleProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_PointsProperty(DependencyProperty* *value);
};

// Polygon
template<typename> struct Polygon_statics {
	static struct _FillRuleProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Polygon, IPolygonStatics>()->_get_FillRuleProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} FillRuleProperty;
	static struct _PointsProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Polygon, IPolygonStatics>()->_get_PointsProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} PointsProperty;
};
template<typename X> typename Polygon_statics<X>::_FillRuleProperty Polygon_statics<X>::FillRuleProperty;
template<typename X> typename Polygon_statics<X>::_PointsProperty Polygon_statics<X>::PointsProperty;

template<typename X> struct statics<Polygon, X> : X, Windows::UI::Xaml::Shapes::Polygon_statics<void> {
	typedef typename X::root_type Polygon;
};
struct Polygon : generate<Polygon> {};

// IPolyline
struct IPolyline_raw : IInspectable {
	virtual STDMETHODIMP _get_FillRule(Media::FillRule *value);
	virtual STDMETHODIMP _put_FillRule(Media::FillRule value);
	virtual STDMETHODIMP _get_Points(Media::PointCollection* *value);
	virtual STDMETHODIMP _put_Points(Media::PointCollection* value);
};
template<typename X> struct IPolyline_adaptor : X {
	union {
		struct : property {
			Media::FillRule get() { Media::FillRule value; hrcheck(enc(&IPolyline_adaptor::FillRule)->_get_FillRule(&value)); return value; }
			Media::FillRule operator()() { return get(); }
			operator Media::FillRule () { return get(); }
			void put(Media::FillRule value) { hrcheck(enc(&IPolyline_adaptor::FillRule)->_put_FillRule(value)); }
			void operator=(Media::FillRule value) { put(value); }
			void operator()(Media::FillRule value) { put(value); }
		} FillRule;
		struct : property {
			ptr<Media::PointCollection> get() { Media::PointCollection* value; hrcheck(enc(&IPolyline_adaptor::Points)->_get_Points(&value)); return from_abi(value); }
			ptr<Media::PointCollection> operator()() { return get(); }
			operator ptr<Media::PointCollection> () { return get(); }
			ptr<Media::PointCollection> operator->() { return get(); }
			void put(pptr<Media::PointCollection> value) { hrcheck(enc(&IPolyline_adaptor::Points)->_put_Points(value)); }
			void operator=(pptr<Media::PointCollection> value) { put(value); }
			void operator()(pptr<Media::PointCollection> value) { put(value); }
		} Points;
	};
	IPolyline_adaptor() {}
};
template<typename X> struct adapt<IPolyline, X> : Windows::UI::Xaml::Shapes::IPolyline_adaptor<X> { typedef adapt IPolyline; };
struct IPolyline : IPolyline_raw, generate<IPolyline> {};

// IPolylineStatics
struct IPolylineStatics : IInspectable {
	virtual STDMETHODIMP _get_FillRuleProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_PointsProperty(DependencyProperty* *value);
};

// Polyline
template<typename> struct Polyline_statics {
	static struct _FillRuleProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Polyline, IPolylineStatics>()->_get_FillRuleProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} FillRuleProperty;
	static struct _PointsProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Polyline, IPolylineStatics>()->_get_PointsProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} PointsProperty;
};
template<typename X> typename Polyline_statics<X>::_FillRuleProperty Polyline_statics<X>::FillRuleProperty;
template<typename X> typename Polyline_statics<X>::_PointsProperty Polyline_statics<X>::PointsProperty;

template<typename X> struct statics<Polyline, X> : X, Windows::UI::Xaml::Shapes::Polyline_statics<void> {
	typedef typename X::root_type Polyline;
};
struct Polyline : generate<Polyline> {};

// IRectangle
struct IRectangle_raw : IInspectable {
	virtual STDMETHODIMP _get_RadiusX(double *value);
	virtual STDMETHODIMP _put_RadiusX(double value);
	virtual STDMETHODIMP _get_RadiusY(double *value);
	virtual STDMETHODIMP _put_RadiusY(double value);
};
template<typename X> struct IRectangle_adaptor : X {
	union {
		struct : property {
			double get() { double value; hrcheck(enc(&IRectangle_adaptor::RadiusX)->_get_RadiusX(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&IRectangle_adaptor::RadiusX)->_put_RadiusX(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} RadiusX;
		struct : property {
			double get() { double value; hrcheck(enc(&IRectangle_adaptor::RadiusY)->_get_RadiusY(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&IRectangle_adaptor::RadiusY)->_put_RadiusY(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} RadiusY;
	};
	IRectangle_adaptor() {}
};
template<typename X> struct adapt<IRectangle, X> : Windows::UI::Xaml::Shapes::IRectangle_adaptor<X> { typedef adapt IRectangle; };
struct IRectangle : IRectangle_raw, generate<IRectangle> {};

// IRectangleStatics
struct IRectangleStatics : IInspectable {
	virtual STDMETHODIMP _get_RadiusXProperty(DependencyProperty* *value);
	virtual STDMETHODIMP _get_RadiusYProperty(DependencyProperty* *value);
};

// Rectangle
template<typename> struct Rectangle_statics {
	static struct _RadiusXProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Rectangle, IRectangleStatics>()->_get_RadiusXProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} RadiusXProperty;
	static struct _RadiusYProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<Rectangle, IRectangleStatics>()->_get_RadiusYProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} RadiusYProperty;
};
template<typename X> typename Rectangle_statics<X>::_RadiusXProperty Rectangle_statics<X>::RadiusXProperty;
template<typename X> typename Rectangle_statics<X>::_RadiusYProperty Rectangle_statics<X>::RadiusYProperty;

template<typename X> struct statics<Rectangle, X> : X, Windows::UI::Xaml::Shapes::Rectangle_statics<void> {
	typedef typename X::root_type Rectangle;
};
struct Rectangle : generate<Rectangle> {};
}}}}
} // namespace iso_winrt
