#include <cstdlib>
#include <iostream>

#include "audio-context.hpp"
#include "base-audio-context.hpp"

#include <LabSound/core/AudioContext.h>
#include <LabSound/core/DefaultAudioDestinationNode.h>

using namespace v8;
using namespace node;
using namespace std;

#define THIS_AUDIO_CONTEXT                                                    \
	AudioContext *audioContext = ObjectWrap::Unwrap<AudioContext>(info.This());

#define THIS_BASE_CONTEXT                                                    \
	BaseAudioContext *baseAudioContext = ObjectWrap::Unwrap<BaseAudioContext>(info.This());

#define THIS_CHECK                                                            \
	if (baseAudioContext->_isDestroyed) return;

#define DES_CHECK                                                             \
	if (_isDestroyed) return;

#define CACHE_CAS(CACHE, V)                                                   \
	if (audioContext->CACHE == V) {                                           \
		return;                                                               \
	}                                                                         \
	audioContext->CACHE = V;


Nan::Persistent<v8::Function> AudioContext::_constructor;


void AudioContext::init(Local<Object> target) {
	
	Local<FunctionTemplate> proto = Nan::New<FunctionTemplate>(newCtor);
	
	// class AudioContext extends BaseAudioContext
	Local<FunctionTemplate> parent = Nan::New(BaseAudioContext::_protorype);
	proto->Inherit(parent);
	
	
	proto->InstanceTemplate()->SetInternalFieldCount(1);
	proto->SetClassName(JS_STR("AudioContext"));
	
	
	// Accessors
	Local<ObjectTemplate> obj = proto->PrototypeTemplate();
	
	ACCESSOR_R(obj, baseLatency);
	
	// -------- dynamic
	
	
	Nan::SetPrototypeMethod(proto, "suspend", suspend);
	Nan::SetPrototypeMethod(proto, "close", close);
	Nan::SetPrototypeMethod(proto, "getOutputTimestamp", getOutputTimestamp);
	Nan::SetPrototypeMethod(proto, "createMediaElementSource", createMediaElementSource);
	Nan::SetPrototypeMethod(proto, "createMediaStreamSource", createMediaStreamSource);
	Nan::SetPrototypeMethod(proto, "createMediaStreamDestination", createMediaStreamDestination);
	
	// -------- static
	
	Local<Function> ctor = Nan::GetFunction(proto).ToLocalChecked();
	
	
	_constructor.Reset(ctor);
	Nan::Set(target, JS_STR("AudioContext"), ctor);
	
	
}


NAN_METHOD(AudioContext::newCtor) {
	
	v8::Local<v8::Function> superCtor = Nan::New(BaseAudioContext::_constructor);
	
	if (info.Length() > 0) {
		REQ_OBJ_ARG(0, opts);
		v8::Local<v8::Value> argv[] = { JS_BOOL(false), opts };
		superCtor->Call(info.This(), 2, argv);
	} else {
		v8::Local<v8::Value> argv = JS_BOOL(false);
		superCtor->Call(info.This(), 1, &argv);
	}
	
	AudioContext *audioContext = new AudioContext();
	audioContext->Wrap(info.This());
	
	RET_VALUE(info.This());
	
}


AudioContext::AudioContext() {}

AudioContext::~AudioContext() {}


NAN_METHOD(AudioContext::suspend) { THIS_BASE_CONTEXT; THIS_CHECK;
	
	std::cout << "CALL suspend"  << baseAudioContext << std::endl;
	
	
	if (baseAudioContext->_state == BaseAudioContext::Closed) {
		// error
	}
	
	if (baseAudioContext->_state == BaseAudioContext::Suspended) {
		return;
	}
	
	baseAudioContext->_state = BaseAudioContext::Suspended;
	
	// TODO: do something?
	
}


NAN_METHOD(AudioContext::close) { THIS_BASE_CONTEXT; THIS_CHECK;
	
	baseAudioContext->_destroy();
	
}


NAN_METHOD(AudioContext::getOutputTimestamp) { THIS_BASE_CONTEXT; THIS_CHECK;
	
	// FIXME: audioContext->_impl->getOutputTimestamp
	
}


NAN_METHOD(AudioContext::createMediaElementSource) { THIS_BASE_CONTEXT; THIS_CHECK;
	
	REQ_OBJ_ARG(0, mediaElement);
	
	// TODO: do something?
	
}


NAN_METHOD(AudioContext::createMediaStreamSource) { THIS_BASE_CONTEXT; THIS_CHECK;
	
	REQ_OBJ_ARG(0, mediaStream);
	
	// TODO: do something?
	
}


NAN_METHOD(AudioContext::createMediaStreamDestination) { THIS_BASE_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_GETTER(AudioContext::baseLatencyGetter) { THIS_AUDIO_CONTEXT; THIS_BASE_CONTEXT; THIS_CHECK;
	
	RET_VALUE(JS_DOUBLE(audioContext->_baseLatency));
	
}
