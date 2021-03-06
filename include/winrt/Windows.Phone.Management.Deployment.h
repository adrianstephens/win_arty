#pragma once
// generated by isopod tools
// namespaces:
// Windows.Phone.Management.Deployment

#include "Windows.Phone.Management.Deployment.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Management.Deployment.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel {
struct Package;
}
namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
template<typename T> struct IIterable;
}}}

// defs

template<> struct def<Windows::Phone::Management::Deployment::EnterpriseStatus> : enum_type<int> {};
template<> struct def<Windows::Phone::Management::Deployment::EnterpriseEnrollmentStatus> : enum_type<int> {};
template<> struct def<Windows::Phone::Management::Deployment::IEnterprise> : interface_type<> {};
template<> struct def<Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager> : interface_type<> {};
template<> struct def<Windows::Phone::Management::Deployment::Enterprise> : class_type<Platform::Object, Windows::Phone::Management::Deployment::IEnterprise> {};
template<> struct def<Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult> : interface_type<> {};
template<> struct def<Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult> : class_type<Platform::Object, Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult> {};
template<> struct def<Windows::Phone::Management::Deployment::IPackageInstallResult> : interface_type<> {};
template<> struct def<Windows::Phone::Management::Deployment::IPackageInstallResult2> : interface_type<> {};
template<> struct def<Windows::Phone::Management::Deployment::PackageInstallResult> : class_type<Platform::Object, Windows::Phone::Management::Deployment::IPackageInstallResult, Windows::Phone::Management::Deployment::IPackageInstallResult2> {};
template<> struct def<Windows::Phone::Management::Deployment::IInstallationManagerStatics> : interface_type<> {};
template<> struct def<Windows::Phone::Management::Deployment::IInstallationManagerStatics2> : interface_type<> {};
template<> struct def<Windows::Phone::Management::Deployment::InstallationManager> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::Phone::Management::Deployment::EnterpriseEnrollmentManager> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::Phone::Management::Deployment::IEnterprise> { define_guid(0x96592F8D, 0x856C, 0x4426, 0xA9, 0x47, 0xB0, 0x63, 0x7, 0x71, 0x80, 0x78);};
template<> struct uuid<Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager> { define_guid(0x20F9F390, 0x2C69, 0x41D8, 0x88, 0xE6, 0xE4, 0xB3, 0x88, 0x40, 0x26, 0xCB);};
template<> struct uuid<Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult> { define_guid(0x9FF71CE6, 0x90DB, 0x4342, 0xB3, 0x26, 0x17, 0x29, 0xAA, 0x91, 0x30, 0x1C);};
template<> struct uuid<Windows::Phone::Management::Deployment::IPackageInstallResult> { define_guid(0x33E8EED5, 0xF7E, 0x4473, 0x96, 0x7C, 0x7D, 0x6E, 0x1C, 0xE, 0x7D, 0xE1);};
template<> struct uuid<Windows::Phone::Management::Deployment::IPackageInstallResult2> { define_guid(0x7149D909, 0x3FF9, 0x41ED, 0xA7, 0x17, 0x2B, 0xC6, 0x5F, 0xFC, 0x61, 0xD2);};
template<> struct uuid<Windows::Phone::Management::Deployment::IInstallationManagerStatics> { define_guid(0x929AA738, 0x8D49, 0x42AC, 0x80, 0xC9, 0xB4, 0xAD, 0x79, 0x3C, 0x43, 0xF2);};
template<> struct uuid<Windows::Phone::Management::Deployment::IInstallationManagerStatics2> { define_guid(0x7C6C2CBD, 0xFA4A, 0x4C8E, 0xAB, 0x97, 0xD9, 0x59, 0x45, 0x2F, 0x19, 0xE5);};

// types

namespace Windows { namespace Phone { namespace Management { namespace Deployment {

// IEnterprise
struct IEnterprise_raw : IInspectable {
	virtual STDMETHODIMP _get_Id(Platform::Guid *value);
	virtual STDMETHODIMP _get_Name(HSTRING *value);
	virtual STDMETHODIMP _get_WorkplaceId(int *value);
	virtual STDMETHODIMP _get_EnrollmentValidFrom(Foundation::DateTime *value);
	virtual STDMETHODIMP _get_EnrollmentValidTo(Foundation::DateTime *value);
	virtual STDMETHODIMP _get_Status(EnterpriseStatus *value);
};
template<typename X> struct IEnterprise_adaptor : X {
	union {
		struct : property {
			Foundation::DateTime get() { Foundation::DateTime value; hrcheck(enc(&IEnterprise_adaptor::EnrollmentValidFrom)->_get_EnrollmentValidFrom(&value)); return value; }
			Foundation::DateTime operator()() { return get(); }
			operator Foundation::DateTime () { return get(); }
		} EnrollmentValidFrom;
		struct : property {
			Foundation::DateTime get() { Foundation::DateTime value; hrcheck(enc(&IEnterprise_adaptor::EnrollmentValidTo)->_get_EnrollmentValidTo(&value)); return value; }
			Foundation::DateTime operator()() { return get(); }
			operator Foundation::DateTime () { return get(); }
		} EnrollmentValidTo;
		struct : property {
			Platform::Guid get() { Platform::Guid value; hrcheck(enc(&IEnterprise_adaptor::Id)->_get_Id(&value)); return value; }
			Platform::Guid operator()() { return get(); }
			operator Platform::Guid () { return get(); }
		} Id;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IEnterprise_adaptor::Name)->_get_Name(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Name;
		struct : property {
			EnterpriseStatus get() { EnterpriseStatus value; hrcheck(enc(&IEnterprise_adaptor::Status)->_get_Status(&value)); return value; }
			EnterpriseStatus operator()() { return get(); }
			operator EnterpriseStatus () { return get(); }
		} Status;
		struct : property {
			int get() { int value; hrcheck(enc(&IEnterprise_adaptor::WorkplaceId)->_get_WorkplaceId(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} WorkplaceId;
	};
	IEnterprise_adaptor() {}
};
template<typename X> struct adapt<IEnterprise, X> : Windows::Phone::Management::Deployment::IEnterprise_adaptor<X> { typedef adapt IEnterprise; };
struct IEnterprise : IEnterprise_raw, generate<IEnterprise> {};

// IEnterpriseEnrollmentManager
struct IEnterpriseEnrollmentManager : IInspectable {
	virtual STDMETHODIMP _get_EnrolledEnterprises(Foundation::Collections::IVectorView<Enterprise*>* *result);
	virtual STDMETHODIMP _get_CurrentEnterprise(Enterprise* *result);
	virtual STDMETHODIMP _ValidateEnterprisesAsync(Foundation::IAsyncAction* *result);
	virtual STDMETHODIMP _RequestEnrollmentAsync(HSTRING enrollmentToken, Foundation::IAsyncOperation<EnterpriseEnrollmentResult*>* *result);
	virtual STDMETHODIMP _RequestUnenrollmentAsync(Enterprise* enterprise, Foundation::IAsyncOperation<bool>* *result);
};

// Enterprise
template<typename X> struct statics<Enterprise, X> : X {
	typedef typename X::root_type Enterprise;
};
struct Enterprise : generate<Enterprise> {};

// IEnterpriseEnrollmentResult
struct IEnterpriseEnrollmentResult_raw : IInspectable {
	virtual STDMETHODIMP _get_EnrolledEnterprise(Enterprise* *result);
	virtual STDMETHODIMP _get_Status(EnterpriseEnrollmentStatus *value);
};
template<typename X> struct IEnterpriseEnrollmentResult_adaptor : X {
	union {
		struct : property {
			ptr<Enterprise> get() { Enterprise* result; hrcheck(enc(&IEnterpriseEnrollmentResult_adaptor::EnrolledEnterprise)->_get_EnrolledEnterprise(&result)); return from_abi(result); }
			ptr<Enterprise> operator()() { return get(); }
			operator ptr<Enterprise> () { return get(); }
			ptr<Enterprise> operator->() { return get(); }
		} EnrolledEnterprise;
		struct : property {
			EnterpriseEnrollmentStatus get() { EnterpriseEnrollmentStatus value; hrcheck(enc(&IEnterpriseEnrollmentResult_adaptor::Status)->_get_Status(&value)); return value; }
			EnterpriseEnrollmentStatus operator()() { return get(); }
			operator EnterpriseEnrollmentStatus () { return get(); }
		} Status;
	};
	IEnterpriseEnrollmentResult_adaptor() {}
};
template<typename X> struct adapt<IEnterpriseEnrollmentResult, X> : Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult_adaptor<X> { typedef adapt IEnterpriseEnrollmentResult; };
struct IEnterpriseEnrollmentResult : IEnterpriseEnrollmentResult_raw, generate<IEnterpriseEnrollmentResult> {};

// EnterpriseEnrollmentResult
template<typename X> struct statics<EnterpriseEnrollmentResult, X> : X {
	typedef typename X::root_type EnterpriseEnrollmentResult;
};
struct EnterpriseEnrollmentResult : generate<EnterpriseEnrollmentResult> {};

// IPackageInstallResult
struct IPackageInstallResult_raw : IInspectable {
	virtual STDMETHODIMP _get_ProductId(HSTRING *value);
	virtual STDMETHODIMP _get_InstallState(Windows::Management::Deployment::PackageInstallState *value);
};
template<typename X> struct IPackageInstallResult_adaptor : X {
	union {
		struct : property {
			Windows::Management::Deployment::PackageInstallState get() { Windows::Management::Deployment::PackageInstallState value; hrcheck(enc(&IPackageInstallResult_adaptor::InstallState)->_get_InstallState(&value)); return value; }
			Windows::Management::Deployment::PackageInstallState operator()() { return get(); }
			operator Windows::Management::Deployment::PackageInstallState () { return get(); }
		} InstallState;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IPackageInstallResult_adaptor::ProductId)->_get_ProductId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ProductId;
	};
	IPackageInstallResult_adaptor() {}
};
template<typename X> struct adapt<IPackageInstallResult, X> : Windows::Phone::Management::Deployment::IPackageInstallResult_adaptor<X> { typedef adapt IPackageInstallResult; };
struct IPackageInstallResult : IPackageInstallResult_raw, generate<IPackageInstallResult> {};

// IPackageInstallResult2
struct IPackageInstallResult2_raw : IInspectable {
	virtual STDMETHODIMP _get_ErrorText(HSTRING *value);
};
template<typename X> struct IPackageInstallResult2_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IPackageInstallResult2_adaptor::ErrorText)->_get_ErrorText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ErrorText;
	};
	IPackageInstallResult2_adaptor() {}
};
template<typename X> struct adapt<IPackageInstallResult2, X> : Windows::Phone::Management::Deployment::IPackageInstallResult2_adaptor<X> { typedef adapt IPackageInstallResult2; };
struct IPackageInstallResult2 : IPackageInstallResult2_raw, generate<IPackageInstallResult2> {};

// PackageInstallResult
template<typename X> struct statics<PackageInstallResult, X> : X {
	typedef typename X::root_type PackageInstallResult;
};
struct PackageInstallResult : generate<PackageInstallResult> {};

// IInstallationManagerStatics
struct IInstallationManagerStatics : IInspectable {
	virtual STDMETHODIMP _AddPackageAsync(HSTRING title, Foundation::Uri* sourceLocation, Foundation::IAsyncOperationWithProgress<PackageInstallResult*, unsigned>* *asyncInfo);
	virtual STDMETHODIMP _AddPackagePreloadedAsync(HSTRING title, Foundation::Uri* sourceLocation, HSTRING instanceId, HSTRING offerId, Foundation::Uri* license, Foundation::IAsyncOperationWithProgress<PackageInstallResult*, unsigned>* *asyncInfo);
	virtual STDMETHODIMP _GetPendingPackageInstalls(Foundation::Collections::IIterable<Foundation::IAsyncOperationWithProgress<PackageInstallResult*, unsigned>*>* *items);
	virtual STDMETHODIMP _FindPackagesForCurrentPublisher(Foundation::Collections::IIterable<Windows::ApplicationModel::Package*>* *items);
	virtual STDMETHODIMP _FindPackages(Foundation::Collections::IIterable<Windows::ApplicationModel::Package*>* *items);
};

// IInstallationManagerStatics2
struct IInstallationManagerStatics2 : IInspectable {
	virtual STDMETHODIMP _RemovePackageAsync(HSTRING packageFullName, Windows::Management::Deployment::RemovalOptions removalOptions, Foundation::IAsyncOperationWithProgress<PackageInstallResult*, unsigned>* *asyncInfo);
	virtual STDMETHODIMP _RegisterPackageAsync(Foundation::Uri* manifestUri, Foundation::Collections::IIterable<Foundation::Uri*>* dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, Foundation::IAsyncOperationWithProgress<PackageInstallResult*, unsigned>* *asyncInfo);
	virtual STDMETHODIMP _FindPackagesByNamePublisher(HSTRING packageName, HSTRING packagePublisher, Foundation::Collections::IIterable<Windows::ApplicationModel::Package*>* *items);
};

// InstallationManager
template<typename> struct InstallationManager_statics {
	static ptr<Foundation::IAsyncOperationWithProgress<ptr<PackageInstallResult>, unsigned>> RemovePackageAsync(hstring_ref packageFullName, Windows::Management::Deployment::RemovalOptions removalOptions) { Foundation::IAsyncOperationWithProgress<PackageInstallResult*, unsigned>* asyncInfo; hrcheck(get_activation_factory<InstallationManager, IInstallationManagerStatics2>()->_RemovePackageAsync(packageFullName, removalOptions, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::IAsyncOperationWithProgress<ptr<PackageInstallResult>, unsigned>> RegisterPackageAsync(pptr<Foundation::Uri> manifestUri, pptr<Foundation::Collections::IIterable<ptr<Foundation::Uri>>> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions) { Foundation::IAsyncOperationWithProgress<PackageInstallResult*, unsigned>* asyncInfo; hrcheck(get_activation_factory<InstallationManager, IInstallationManagerStatics2>()->_RegisterPackageAsync(manifestUri, to_abi(dependencyPackageUris), deploymentOptions, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::Collections::IIterable<ptr<Windows::ApplicationModel::Package>>> FindPackages(hstring_ref packageName, hstring_ref packagePublisher) { Foundation::Collections::IIterable<Windows::ApplicationModel::Package*>* items; hrcheck(get_activation_factory<InstallationManager, IInstallationManagerStatics2>()->_FindPackagesByNamePublisher(packageName, packagePublisher, &items)); return from_abi(items); }
	static ptr<Foundation::IAsyncOperationWithProgress<ptr<PackageInstallResult>, unsigned>> AddPackageAsync(hstring_ref title, pptr<Foundation::Uri> sourceLocation) { Foundation::IAsyncOperationWithProgress<PackageInstallResult*, unsigned>* asyncInfo; hrcheck(get_activation_factory<InstallationManager, IInstallationManagerStatics>()->_AddPackageAsync(title, sourceLocation, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::IAsyncOperationWithProgress<ptr<PackageInstallResult>, unsigned>> AddPackageAsync(hstring_ref title, pptr<Foundation::Uri> sourceLocation, hstring_ref instanceId, hstring_ref offerId, pptr<Foundation::Uri> license) { Foundation::IAsyncOperationWithProgress<PackageInstallResult*, unsigned>* asyncInfo; hrcheck(get_activation_factory<InstallationManager, IInstallationManagerStatics>()->_AddPackagePreloadedAsync(title, sourceLocation, instanceId, offerId, license, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::Collections::IIterable<ptr<Foundation::IAsyncOperationWithProgress<ptr<PackageInstallResult>, unsigned>>>> GetPendingPackageInstalls() { Foundation::Collections::IIterable<Foundation::IAsyncOperationWithProgress<PackageInstallResult*, unsigned>*>* items; hrcheck(get_activation_factory<InstallationManager, IInstallationManagerStatics>()->_GetPendingPackageInstalls(&items)); return from_abi(items); }
	static ptr<Foundation::Collections::IIterable<ptr<Windows::ApplicationModel::Package>>> FindPackagesForCurrentPublisher() { Foundation::Collections::IIterable<Windows::ApplicationModel::Package*>* items; hrcheck(get_activation_factory<InstallationManager, IInstallationManagerStatics>()->_FindPackagesForCurrentPublisher(&items)); return from_abi(items); }
	static ptr<Foundation::Collections::IIterable<ptr<Windows::ApplicationModel::Package>>> FindPackages() { Foundation::Collections::IIterable<Windows::ApplicationModel::Package*>* items; hrcheck(get_activation_factory<InstallationManager, IInstallationManagerStatics>()->_FindPackages(&items)); return from_abi(items); }
};

template<typename X> struct statics<InstallationManager, X> : X, Windows::Phone::Management::Deployment::InstallationManager_statics<void> {
	typedef typename X::root_type InstallationManager;
};
struct InstallationManager : generate<InstallationManager> {};

// EnterpriseEnrollmentManager
template<typename> struct EnterpriseEnrollmentManager_statics {
	static struct _CurrentEnterprise : property {
		ptr<Enterprise> get() { Enterprise* result; hrcheck(get_activation_factory<EnterpriseEnrollmentManager, IEnterpriseEnrollmentManager>()->_get_CurrentEnterprise(&result)); return from_abi(result); }
		ptr<Enterprise> operator()() { return get(); }
		operator ptr<Enterprise> () { return get(); }
		ptr<Enterprise> operator->() { return get(); }
	} CurrentEnterprise;
	static struct _EnrolledEnterprises : property {
		ptr<Foundation::Collections::IVectorView<ptr<Enterprise>>> get() { Foundation::Collections::IVectorView<Enterprise*>* result; hrcheck(get_activation_factory<EnterpriseEnrollmentManager, IEnterpriseEnrollmentManager>()->_get_EnrolledEnterprises(&result)); return from_abi(result); }
		ptr<Foundation::Collections::IVectorView<ptr<Enterprise>>> operator()() { return get(); }
		operator ptr<Foundation::Collections::IVectorView<ptr<Enterprise>>> () { return get(); }
		ptr<Foundation::Collections::IVectorView<ptr<Enterprise>>> operator->() { return get(); }
	} EnrolledEnterprises;
	static ptr<Foundation::IAsyncAction> ValidateEnterprisesAsync() { Foundation::IAsyncAction* result; hrcheck(get_activation_factory<EnterpriseEnrollmentManager, IEnterpriseEnrollmentManager>()->_ValidateEnterprisesAsync(&result)); return from_abi(result); }
	static ptr<Foundation::IAsyncOperation<ptr<EnterpriseEnrollmentResult>>> RequestEnrollmentAsync(hstring_ref enrollmentToken) { Foundation::IAsyncOperation<EnterpriseEnrollmentResult*>* result; hrcheck(get_activation_factory<EnterpriseEnrollmentManager, IEnterpriseEnrollmentManager>()->_RequestEnrollmentAsync(enrollmentToken, &result)); return from_abi(result); }
	static ptr<Foundation::IAsyncOperation<bool>> RequestUnenrollmentAsync(pptr<Enterprise> enterprise) { Foundation::IAsyncOperation<bool>* result; hrcheck(get_activation_factory<EnterpriseEnrollmentManager, IEnterpriseEnrollmentManager>()->_RequestUnenrollmentAsync(enterprise, &result)); return from_abi(result); }
};
template<typename X> typename EnterpriseEnrollmentManager_statics<X>::_CurrentEnterprise EnterpriseEnrollmentManager_statics<X>::CurrentEnterprise;
template<typename X> typename EnterpriseEnrollmentManager_statics<X>::_EnrolledEnterprises EnterpriseEnrollmentManager_statics<X>::EnrolledEnterprises;

template<typename X> struct statics<EnterpriseEnrollmentManager, X> : X, Windows::Phone::Management::Deployment::EnterpriseEnrollmentManager_statics<void> {
	typedef typename X::root_type EnterpriseEnrollmentManager;
};
struct EnterpriseEnrollmentManager : generate<EnterpriseEnrollmentManager> {};
}}}}
} // namespace iso_winrt
