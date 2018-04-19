#include "winrt/base.h"
#include "winrt/coroutine.h"
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Media.Audio.h"
#include "winrt/Windows.Media.Devices.h"
#include "winrt/Windows.Media.MediaProperties.h"
//#include "base/maths.h"

using namespace iso_winrt;
using namespace Windows::Foundation;
using namespace Windows::Media;
using namespace Windows::Media::Devices;
using namespace Windows::Media::Capture;
using namespace Windows::Media::Audio;
using namespace Windows::Media::Render;
using namespace Windows::Media::MediaProperties;

class WindowsAudioGraph {
	ptr<AudioGraph>				graph;
	ptr<AudioDeviceOutputNode>	device_output;
	ptr<AudioDeviceInputNode>	device_input;

	// the terminology is weird, this is from the point of view of the speakers / headphones
	ptr<AudioFrameInputNode>	data_output;	// we feed "in" samples to this node that gets routed to speaker (of some sort)
	ptr<AudioFrameOutputNode>	data_input;		// from the point of view of the microphone, we grab samples "out" of this node

	EventRegistrationToken		cookie;
	float						angle;

	template<typename T> struct Frame {
		T			*p;
		unsigned	samples, chans, rate;

		Frame() : p(0), samples(0), chans(0), rate(0) {}
		Frame(ptr<AudioEncodingProperties> props) : p(0), samples(0) { Init(props); }

		void	Init(ptr<AudioEncodingProperties> props) {
			chans	= props->ChannelCount;
			rate	= props->SampleRate;
		}

		Frame& GetData(ptr<AudioBuffer> buffer) {
			BYTE		*bytes;
			unsigned	byte_count;
			((ptr<IMemoryBufferByteAccess>)buffer->CreateReference())->GetBuffer(&bytes, &byte_count);
			p		= (T*)bytes;
			samples = byte_count / (sizeof(T) * chans);
			return *this;
		}

		ptr<AudioFrame> MakeAudioFrame(unsigned _samples) {
			return ref_new<AudioFrame>(_samples * chans * (unsigned)sizeof(T));
		}
		
		void Clear() {
			if (p)
				memset(p, 0, chans * samples * sizeof(T));
		}
		void Add(const Frame &input, float boost) {
			for (int s = 0; s < samples && s < input.samples; s++) {
				p[s * chans + 0] += input.p[s * input.chans] * boost;
				p[s * chans + 1] += input.p[s * input.chans] * boost;
			}
		}
		void Add(const Frame &input, float boost, float rate) {
			if (input.samples == 0)
				return;
			for (int s = 0; s < samples; s++) {
				int	si = int(s * rate) % input.samples;
				p[s * chans + 0] += input.p[si * input.chans] * boost;
				p[s * chans + 1] += input.p[si * input.chans] * boost;
			}
		}
	};
	/*
	template<typename T> static double AddSineWave(const Frame<T> &output, double angle, double frequency, double gain) {
		const double pi		= 3.141592653589793;
		double		angle_increment	= frequency * 2 * pi / output.rate;
		unsigned	chans	= output.chans;
		T			*p		= output.p;
		for (auto s = 0; s < output.samples; s++) {
			T y = sin(angle) * gain;

			p[s * chans + 0] += y;	//left
			p[s * chans + 1] += y;	//right

			angle = mod(angle + angle_increment, 2 * pi);
		}
		return angle;
	}
	*/
	void AudioOutputCallback(ptr<AudioFrameInputNode> sender, int output_sample_count) {
		// A maximum of 64 frames can be queued in the AudioFrameInputNode at one time - more than 64 frames will result in an error.

		if (output_sample_count > 0) {
			Frame<float>		frame_out(sender->EncodingProperties);
			ptr<AudioFrame>		frame	= frame_out.MakeAudioFrame(output_sample_count);

			{
				ptr<AudioBuffer>	buffer_out	= frame->LockBuffer(AudioBufferAccessMode::Write);
				frame_out.GetData(buffer_out);
				frame_out.Clear();
			
				//angle = AddSineWave(frame_out, angle, 200.0, 0.3);

				if (data_input && data_input->ConsumeInput()) {
					if (ptr<AudioFrame> frame = data_input->GetFrame()) {
						Frame<float>		frame_in(data_input->EncodingProperties);
						bool input_discontinuity_detected	= frame->IsDiscontinuous();
						frame_out.Add(frame_in.GetData(frame->LockBuffer(AudioBufferAccessMode::Read)), 4, 1.5f);
					}
				}
			}

			sender->AddFrame(frame);
		}
	}

public:
	WindowsAudioGraph() : angle(0) {}

	ptr<IAsyncAction> Start() {
		ptr<AudioGraphSettings> settings = ref_new<AudioGraphSettings>(AudioRenderCategory::Media);
		settings->QuantumSizeSelectionMode(QuantumSizeSelectionMode::LowestLatency);
		auto result = co_await AudioGraph::CreateAsync(settings);
		if (result->Status != AudioGraphCreationStatus::Success)
			return;

		graph = result->Graph();

		// Create a device output node
		auto deviceOutputNodeResult = co_await graph->CreateDeviceOutputNodeAsync();
		if (deviceOutputNodeResult->Status != AudioDeviceNodeCreationStatus::Success)
			return;

		device_output = deviceOutputNodeResult->DeviceOutputNode;

		// Create a device input node using the default audio input device
		auto deviceInputNodeResult = co_await graph->CreateDeviceInputNodeAsync(MediaCategory::Other);
		if (deviceInputNodeResult->Status == AudioDeviceNodeCreationStatus::Success) {
			device_input	= deviceInputNodeResult->DeviceInputNode;
			data_input		= graph->CreateFrameOutputNode();
	
			// this is muy importante, it routes audio from the input device to the input data node
			device_input->AddOutgoingConnection(data_input);
		}

		// Create the FrameInputNode as the same format as the graph
		ptr<AudioNodeEmitter> emitter;
		data_output	= graph->CreateFrameInputNode(graph->EncodingProperties(), emitter);

		// run this node to the output device
		data_output->AddOutgoingConnection(device_output);

		// Initialize the Frame Input Node in the stopped state
		data_output->Stop();

		// This event is triggered when the node is required to provide data
		cookie = data_output->QuantumStarted += [this](ptr<AudioFrameInputNode> &&sender, ptr<FrameInputNodeQuantumStartedEventArgs> &&args) {
			AudioOutputCallback(sender, args->RequiredSamples);
		};

		// Start the graph since we will only start/stop the frame input node
		graph->Start();

		if (data_output)
			data_output->Start();

		if (data_input) {
			data_input->Start();
			data_input->Reset();
		}
	}

	void Stop() {
		if (data_input)
			data_input->Stop();

		if (data_output) {
			data_output->QuantumStarted -= cookie;
			data_output->Stop();
		}

		if (graph)
			graph->Stop();
	}
};


void test_WindowsAudioGraph() {
	WindowsAudioGraph audio;

	co_await audio.Start();
	co_await delay(40);
	audio.Stop();
}
