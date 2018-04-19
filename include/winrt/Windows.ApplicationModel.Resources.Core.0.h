#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace Resources { namespace Core {
struct ResourceLayoutInfo {
	unsigned MajorVersion;
	unsigned MinorVersion;
	unsigned ResourceSubtreeCount;
	unsigned NamedResourceCount;
	int Checksum;
};
struct IResourceManager;
struct INamedResource;
struct NamedResource;
struct IResourceMap;
struct ResourceMap;
enum class ResourceQualifierPersistence : int {
	None = 0,
	LocalMachine = 1,
};
struct IResourceContextStatics3;
struct IResourceContextStatics2;
struct IResourceContextStatics;
struct IResourceContext;
struct ResourceContext;
struct IResourceManager2;
struct IResourceManagerStatics;
struct ResourceManager;
struct IResourceQualifier;
struct ResourceQualifier;
struct IResourceCandidate;
struct IResourceCandidate2;
struct ResourceCandidate;
struct ResourceMapIterator;
struct ResourceMapMapView;
struct ResourceMapMapViewIterator;
struct ResourceQualifierObservableMap;
struct ResourceQualifierMapView;
struct ResourceQualifierVectorView;
struct ResourceCandidateVectorView;
struct ResourceContextLanguagesVectorView;
}}}}
} // namespace iso_winrt