#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Media { namespace Audio {
struct IAudioStateMonitorStatics;
struct IAudioStateMonitor;
struct AudioStateMonitor;
enum class AudioGraphCreationStatus : int {
	Success = 0,
	DeviceNotAvailable = 1,
	FormatNotSupported = 2,
	UnknownFailure = 3,
};
enum class QuantumSizeSelectionMode : int {
	SystemDefault = 0,
	LowestLatency = 1,
	ClosestToDesired = 2,
};
struct ICreateAudioGraphResult;
struct IAudioGraphStatics;
struct IAudioGraph3;
struct IAudioGraph;
struct IAudioGraph2;
struct AudioGraph;
struct CreateAudioGraphResult;
struct IAudioGraphSettingsFactory;
struct IAudioGraphSettings2;
struct IAudioGraphSettings;
struct AudioGraphSettings;
enum class AudioDeviceNodeCreationStatus : int {
	Success = 0,
	DeviceNotAvailable = 1,
	FormatNotSupported = 2,
	UnknownFailure = 3,
	AccessDenied = 4,
};
enum class AudioFileNodeCreationStatus : int {
	Success = 0,
	FileNotFound = 1,
	InvalidFileType = 2,
	FormatNotSupported = 3,
	UnknownFailure = 4,
};
struct ICreateAudioDeviceInputNodeResult;
struct IAudioNode;
struct IAudioInputNode;
struct IAudioInputNode2;
struct IAudioDeviceInputNode;
struct AudioDeviceInputNode;
struct CreateAudioDeviceInputNodeResult;
struct ICreateAudioDeviceOutputNodeResult;
struct IAudioNodeWithListener;
struct IAudioDeviceOutputNode;
struct AudioDeviceOutputNode;
struct CreateAudioDeviceOutputNodeResult;
struct ICreateAudioFileInputNodeResult;
struct IAudioFileInputNode;
struct AudioFileInputNode;
struct CreateAudioFileInputNodeResult;
struct ICreateAudioFileOutputNodeResult;
struct IAudioFileOutputNode;
struct AudioFileOutputNode;
struct CreateAudioFileOutputNodeResult;
enum class MediaSourceAudioInputNodeCreationStatus : int {
	Success = 0,
	FormatNotSupported = 1,
	NetworkError = 2,
	UnknownFailure = 3,
};
struct ICreateMediaSourceAudioInputNodeResult;
struct IMediaSourceAudioInputNode;
struct MediaSourceAudioInputNode;
struct CreateMediaSourceAudioInputNodeResult;
enum class AudioGraphUnrecoverableError : int {
	None = 0,
	AudioDeviceLost = 1,
	AudioSessionDisconnected = 2,
	UnknownFailure = 3,
};
struct IAudioGraphUnrecoverableErrorOccurredEventArgs;
struct AudioGraphUnrecoverableErrorOccurredEventArgs;
struct AudioGraphBatchUpdater;
struct IAudioFrameInputNode;
struct AudioFrameInputNode;
struct IAudioFrameOutputNode;
struct AudioFrameOutputNode;
struct AudioSubmixNode;
enum class AudioNodeEmitterSettings : unsigned {
	None = 0x0,
	DisableDoppler = 0x1,
};
struct IAudioNodeEmitterFactory;
enum class SpatialAudioModel : int {
	ObjectBased = 0,
	FoldDown = 1,
};
struct IAudioNodeEmitter2;
struct IAudioNodeEmitter;
struct AudioNodeEmitter;
struct IAudioNodeListener;
struct AudioNodeListener;
struct IAudioGraphConnection;
struct AudioGraphConnection;
struct IAudioFrameCompletedEventArgs;
struct AudioFrameCompletedEventArgs;
struct IFrameInputNodeQuantumStartedEventArgs;
struct FrameInputNodeQuantumStartedEventArgs;
struct IEqualizerBand;
struct EqualizerBand;
struct IEqualizerEffectDefinitionFactory;
struct IEqualizerEffectDefinition;
struct EqualizerEffectDefinition;
struct IReverbEffectDefinitionFactory;
struct IReverbEffectDefinition;
struct ReverbEffectDefinition;
struct IEchoEffectDefinitionFactory;
struct IEchoEffectDefinition;
struct EchoEffectDefinition;
struct ILimiterEffectDefinitionFactory;
struct ILimiterEffectDefinition;
struct LimiterEffectDefinition;
enum class AudioNodeEmitterShapeKind : int {
	Omnidirectional = 0,
	Cone = 1,
};
enum class AudioNodeEmitterDecayKind : int {
	Natural = 0,
	Custom = 1,
};
struct IAudioNodeEmitterConeProperties;
struct AudioNodeEmitterConeProperties;
struct IAudioNodeEmitterShape;
struct IAudioNodeEmitterShapeStatics;
struct AudioNodeEmitterShape;
struct IAudioNodeEmitterNaturalDecayModelProperties;
struct AudioNodeEmitterNaturalDecayModelProperties;
struct IAudioNodeEmitterDecayModel;
struct IAudioNodeEmitterDecayModelStatics;
struct AudioNodeEmitterDecayModel;
}}}
} // namespace iso_winrt
