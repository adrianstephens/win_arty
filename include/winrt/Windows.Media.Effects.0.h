#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Media { namespace Effects {
struct IVideoCompositorDefinition;
struct IVideoCompositorDefinitionFactory;
struct VideoCompositorDefinition;
struct ICompositeVideoFrameContext;
struct CompositeVideoFrameContext;
enum class AudioEffectType : int {
	Other = 0,
	AcousticEchoCancellation = 1,
	NoiseSuppression = 2,
	AutomaticGainControl = 3,
	BeamForming = 4,
	ConstantToneRemoval = 5,
	Equalizer = 6,
	LoudnessEqualizer = 7,
	BassBoost = 8,
	VirtualSurround = 9,
	VirtualHeadphones = 10,
	SpeakerFill = 11,
	RoomCorrection = 12,
	BassManagement = 13,
	EnvironmentalEffects = 14,
	SpeakerProtection = 15,
	SpeakerCompensation = 16,
	DynamicRangeCompression = 17,
};
struct IAudioEffect;
struct AudioEffect;
struct IAudioEffectsManagerStatics;
struct IAudioRenderEffectsManager2;
struct IAudioRenderEffectsManager;
struct AudioRenderEffectsManager;
struct IAudioCaptureEffectsManager;
struct AudioCaptureEffectsManager;
struct AudioEffectsManager;
enum class MediaEffectClosedReason : int {
	Done = 0,
	UnknownError = 1,
	UnsupportedEncodingFormat = 2,
	EffectCurrentlyUnloaded = 3,
};
struct IVideoCompositor;
struct IVideoEffectDefinition;
struct IVideoEffectDefinitionFactory;
struct VideoEffectDefinition;
struct IAudioEffectDefinition;
struct IAudioEffectDefinitionFactory;
struct AudioEffectDefinition;
enum class MediaMemoryTypes : int {
	Gpu = 0,
	Cpu = 1,
	GpuAndCpu = 2,
};
struct IProcessVideoFrameContext;
struct IBasicVideoEffect;
struct ProcessVideoFrameContext;
struct IProcessAudioFrameContext;
struct IBasicAudioEffect;
struct ProcessAudioFrameContext;
struct IVideoTransformEffectDefinition;
struct IVideoTransformSphericalProjection;
struct IVideoTransformEffectDefinition2;
struct VideoTransformSphericalProjection;
struct VideoTransformEffectDefinition;
struct ISlowMotionEffectDefinition;
struct SlowMotionEffectDefinition;
}}}
} // namespace iso_winrt
