#include <cstdlib>
#include <iostream>

#include "base-audio-context.hpp"

using namespace v8;
using namespace node;
using namespace std;


#define THIS_BASE_AUDIO_CONTEXT                                                    \
	BaseAudioContext *baseAudioContext = ObjectWrap::Unwrap<BaseAudioContext>(info.This());

#define THIS_CHECK                                                            \
	if (baseAudioContext->_isDestroyed) return;

#define DES_CHECK                                                             \
	if (_isDestroyed) return;

#define CACHE_CAS(CACHE, V)                                                   \
	if (baseAudioContext->CACHE == V) {                                           \
		return;                                                               \
	}                                                                         \
	baseAudioContext->CACHE = V;


Nan::Persistent<v8::Function> BaseAudioContext::_constructor;


void BaseAudioContext::init(Local<Object> target) {
	
	Local<FunctionTemplate> proto = Nan::New<FunctionTemplate>(newCtor);
	
	proto->InstanceTemplate()->SetInternalFieldCount(1);
	proto->SetClassName(JS_STR("BaseAudioContext"));
	
	
	// Accessors
	Local<ObjectTemplate> obj = proto->PrototypeTemplate();
	ACCESSOR_R(obj, isDestroyed);
	
	ACCESSOR_R(obj, destination);
	ACCESSOR_R(obj, currentTime);
	ACCESSOR_R(obj, sampleRate);
	ACCESSOR_R(obj, listener);
	ACCESSOR_R(obj, state);
	
	// -------- dynamic
	
	
	
	Nan::SetPrototypeMethod(proto, "destroy", destroy);
	
	Nan::SetPrototypeMethod(proto, "createBuffer", createBuffer);
	Nan::SetPrototypeMethod(proto, "decodeAudioData", decodeAudioData);
	Nan::SetPrototypeMethod(proto, "createBufferSource", createBufferSource);
	Nan::SetPrototypeMethod(proto, "createConstantSource", createConstantSource);
	Nan::SetPrototypeMethod(proto, "createGain", createGain);
	Nan::SetPrototypeMethod(proto, "createDelay", createDelay);
	Nan::SetPrototypeMethod(proto, "createBiquadFilter", createBiquadFilter);
	Nan::SetPrototypeMethod(proto, "createIIRFilter", createIIRFilter);
	Nan::SetPrototypeMethod(proto, "createWaveShaper", createWaveShaper);
	Nan::SetPrototypeMethod(proto, "createPanner", createPanner);
	Nan::SetPrototypeMethod(proto, "createConvolver", createConvolver);
	Nan::SetPrototypeMethod(proto, "createDynamicsCompressor", createDynamicsCompressor);
	Nan::SetPrototypeMethod(proto, "createAnalyser", createAnalyser);
	Nan::SetPrototypeMethod(proto, "createScriptProcessor", createScriptProcessor);
	Nan::SetPrototypeMethod(proto, "createStereoPanner", createStereoPanner);
	Nan::SetPrototypeMethod(proto, "createOscillator", createOscillator);
	Nan::SetPrototypeMethod(proto, "createPeriodicWave", createPeriodicWave);
	Nan::SetPrototypeMethod(proto, "createChannelSplitter", createChannelSplitter);
	Nan::SetPrototypeMethod(proto, "createChannelMerger", createChannelMerger);
	Nan::SetPrototypeMethod(proto, "resume", resume);
	Nan::SetPrototypeMethod(proto, "createMediaElementSource", createMediaElementSource);
	Nan::SetPrototypeMethod(proto, "createMediaStreamSource", createMediaStreamSource);
	Nan::SetPrototypeMethod(proto, "createMediaStreamDestination", createMediaStreamDestination);
	
	// -------- static
	
	Local<Function> ctor = Nan::GetFunction(proto).ToLocalChecked();
	
	
	
	
	_constructor.Reset(ctor);
	Nan::Set(target, JS_STR("BaseAudioContext"), ctor);
	
	
}


NAN_METHOD(BaseAudioContext::newCtor) {
	
	CTOR_CHECK("BaseAudioContext");
	
	BaseAudioContext *baseAudioContext = new BaseAudioContext();
	baseAudioContext->Wrap(info.This());
	
	RET_VALUE(info.This());
	
}


BaseAudioContext::BaseAudioContext() {
	
	_isDestroyed = false;
	
}


BaseAudioContext::~BaseAudioContext() {
	
	_destroy();
	
}


void BaseAudioContext::_destroy() { DES_CHECK;
	
	_isDestroyed = true;
	
	
	
}



NAN_METHOD(BaseAudioContext::destroy) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	baseAudioContext->_destroy();
	
}


NAN_METHOD(BaseAudioContext::createBuffer) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	REQ_INT32_ARG(0, numberOfChannels);
	REQ_INT32_ARG(1, numberOfFrames);
	REQ_FLOAT_ARG(2, sampleRate);
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::decodeAudioData) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	REQ_OBJ_ARG(0, audioData);
	REQ_FUN_ARG(1, successCallback);
	REQ_FUN_ARG(2,  errorCallback);
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createBufferSource) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createConstantSource) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createGain) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createDelay) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	REQ_DOUBLE_ARG(0, maxDelayTime);
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createBiquadFilter) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createIIRFilter) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	REQ_OBJ_ARG(0, feedForward);
	REQ_OBJ_ARG(1, feedBack);
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createWaveShaper) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createPanner) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createConvolver) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createDynamicsCompressor) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createAnalyser) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createScriptProcessor) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	REQ_INT32_ARG(0, bufferSize);
	REQ_INT32_ARG(1, numberOfInputChannels);
	REQ_INT32_ARG(2, numberOfOutputChannels);
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createStereoPanner) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createOscillator) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createPeriodicWave) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	REQ_OBJ_ARG(0, real);
	REQ_OBJ_ARG(1, imag);
	REQ_OBJ_ARG(2, options);
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createChannelSplitter) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	REQ_INT32_ARG(0, numberOfOutputs);
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createChannelMerger) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	REQ_INT32_ARG(0, numberOfInputs);
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::resume) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createMediaElementSource) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	REQ_OBJ_ARG(0, mediaElement);
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createMediaStreamSource) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	REQ_OBJ_ARG(0, mediaStream);
	
	// TODO: do something?
	
}


NAN_METHOD(BaseAudioContext::createMediaStreamDestination) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	
	
	// TODO: do something?
	
}



NAN_GETTER(BaseAudioContext::isDestroyedGetter) { THIS_BASE_AUDIO_CONTEXT;
	
	RET_VALUE(JS_BOOL(baseAudioContext->_isDestroyed));
	
}


NAN_GETTER(BaseAudioContext::destinationGetter) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	RET_VALUE(JS_OBJ(baseAudioContext->_destination));
	
}



NAN_GETTER(BaseAudioContext::currentTimeGetter) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	RET_VALUE(JS_DOUBLE(baseAudioContext->_currentTime));
	
}



NAN_GETTER(BaseAudioContext::sampleRateGetter) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	RET_VALUE(JS_FLOAT(baseAudioContext->_sampleRate));
	
}



NAN_GETTER(BaseAudioContext::listenerGetter) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	RET_VALUE(JS_OBJ(baseAudioContext->_listener));
	
}



NAN_GETTER(BaseAudioContext::stateGetter) { THIS_BASE_AUDIO_CONTEXT; THIS_CHECK;
	
	RET_VALUE(JS_UTF8(baseAudioContext->_state));
	
}

