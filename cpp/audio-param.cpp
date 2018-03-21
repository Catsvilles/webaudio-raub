#include <cstdlib>
//#include <iostream> // -> std::cout << "..." << std::endl;


#include "audio-param.hpp"


using namespace v8;
using namespace node;
using namespace std;


// ------ Aux macros

#define THIS_AUDIO_PARAM                                                    \
	AudioParam *audioParam = ObjectWrap::Unwrap<AudioParam>(info.This());

#define THIS_CHECK                                                            \
	if (audioParam->_isDestroyed) return;

#define CACHE_CAS(CACHE, V)                                                   \
	if (audioParam->CACHE == V) {                                           \
		return;                                                               \
	}                                                                         \
	audioParam->CACHE = V;


// ------ Constructor and Destructor

AudioParam::AudioParam() {
	
	_isDestroyed = false;
	
}


AudioParam::~AudioParam() {
	
	_destroy();
	
}


void AudioParam::_destroy() { DES_CHECK;
	
	_isDestroyed = true;
	
}


// ------ Methods and props


NAN_METHOD(AudioParam::setValueAtTime) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	REQ_FLOAT_ARG(0, value);
	REQ_DOUBLE_ARG(1, time);
	
	// TODO: do something?
	
}


NAN_METHOD(AudioParam::linearRampToValueAtTime) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	REQ_FLOAT_ARG(0, value);
	REQ_DOUBLE_ARG(1, time);
	
	// TODO: do something?
	
}


NAN_METHOD(AudioParam::exponentialRampToValueAtTime) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	REQ_FLOAT_ARG(0, value);
	REQ_DOUBLE_ARG(1, time);
	
	// TODO: do something?
	
}


NAN_METHOD(AudioParam::setTargetAtTime) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	REQ_FLOAT_ARG(0, target);
	REQ_DOUBLE_ARG(1, time);
	REQ_DOUBLE_ARG(2, timeConstant);
	
	// TODO: do something?
	
}


NAN_METHOD(AudioParam::setValueCurveAtTime) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	REQ_OBJ_ARG(0, values);
	REQ_DOUBLE_ARG(1, time);
	REQ_DOUBLE_ARG(2, duration);
	
	// TODO: do something?
	
}


NAN_METHOD(AudioParam::cancelScheduledValues) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	REQ_DOUBLE_ARG(0, startTime);
	
	// TODO: do something?
	
}


NAN_METHOD(AudioParam::cancelAndHoldAtTime) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	REQ_DOUBLE_ARG(0, startTime);
	
	// TODO: do something?
	
}


NAN_GETTER(AudioParam::valueGetter) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	RET_VALUE(JS_FLOAT(audioParam->_value));
	
}

NAN_SETTER(AudioParam::valueSetter) { THIS_AUDIO_PARAM; THIS_CHECK; SETTER_FLOAT_ARG;
	
	CACHE_CAS(_value, v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(AudioParam::defaultValueGetter) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	RET_VALUE(JS_FLOAT(audioParam->_defaultValue));
	
}


NAN_GETTER(AudioParam::minValueGetter) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	RET_VALUE(JS_FLOAT(audioParam->_minValue));
	
}


NAN_GETTER(AudioParam::maxValueGetter) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	RET_VALUE(JS_FLOAT(audioParam->_maxValue));
	
}


// ------ System methods and props for ObjectWrap

Nan::Persistent<v8::FunctionTemplate> AudioParam::_protoAudioParam;
Nan::Persistent<v8::Function> AudioParam::_ctorAudioParam;


void AudioParam::init(Local<Object> target) {
	
	Local<FunctionTemplate> proto = Nan::New<FunctionTemplate>(newCtor);
	
	proto->InstanceTemplate()->SetInternalFieldCount(1);
	proto->SetClassName(JS_STR("AudioParam"));
	
	
	// Accessors
	Local<ObjectTemplate> obj = proto->PrototypeTemplate();
	ACCESSOR_R(obj, isDestroyed);
	
	ACCESSOR_RW(obj, value);
	ACCESSOR_R(obj, defaultValue);
	ACCESSOR_R(obj, minValue);
	ACCESSOR_R(obj, maxValue);
	
	// -------- dynamic
	
	Nan::SetPrototypeMethod(proto, "destroy", destroy);
	
	Nan::SetPrototypeMethod(proto, "setValueAtTime", setValueAtTime);
	Nan::SetPrototypeMethod(proto, "linearRampToValueAtTime", linearRampToValueAtTime);
	Nan::SetPrototypeMethod(proto, "exponentialRampToValueAtTime", exponentialRampToValueAtTime);
	Nan::SetPrototypeMethod(proto, "setTargetAtTime", setTargetAtTime);
	Nan::SetPrototypeMethod(proto, "setValueCurveAtTime", setValueCurveAtTime);
	Nan::SetPrototypeMethod(proto, "cancelScheduledValues", cancelScheduledValues);
	Nan::SetPrototypeMethod(proto, "cancelAndHoldAtTime", cancelAndHoldAtTime);
	
	// -------- static
	
	Local<Function> ctor = Nan::GetFunction(proto).ToLocalChecked();
	
	_protoAudioParam.Reset(proto);
	_ctorAudioParam.Reset(ctor);
	
	Nan::Set(target, JS_STR("AudioParam"), ctor);
	
	
}


NAN_METHOD(AudioParam::newCtor) {
	
	CTOR_CHECK("AudioParam");
	
	AudioParam *audioParam = new AudioParam();
	audioParam->Wrap(info.This());
	
	RET_VALUE(info.This());
	
}


NAN_METHOD(AudioParam::destroy) { THIS_AUDIO_PARAM; THIS_CHECK;
	
	audioParam->_destroy();
	
}


NAN_GETTER(AudioParam::isDestroyedGetter) { THIS_AUDIO_PARAM;
	
	RET_VALUE(JS_BOOL(audioParam->_isDestroyed));
	
}
