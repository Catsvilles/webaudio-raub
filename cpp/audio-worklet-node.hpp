#ifndef _AUDIO_WORKLET_NODE_HPP_
#define _AUDIO_WORKLET_NODE_HPP_


#include <addon-tools.hpp>


class AudioWorkletNode : public Nan::ObjectWrap {
	
public:
	
	// Public V8 init
	static void init(v8::Local<v8::Object> target);
	
	void _destroy();
	
	
// Methods and props
protected:
	
	AudioWorkletNode();
	virtual ~AudioWorkletNode();
	
	static Nan::Persistent<v8::FunctionTemplate> _protoAudioWorkletNode; // for inheritance
	static Nan::Persistent<v8::Function> _ctorAudioWorkletNode;
	
	
// System methods and props for ObjectWrap
private:
	
	static NAN_METHOD(newCtor);
	
	static NAN_METHOD(destroy);
	static NAN_GETTER(isDestroyedGetter);
	
	
	
	static NAN_GETTER(parametersGetter);
	
	static NAN_GETTER(portGetter);
	
	static NAN_GETTER(onprocessorerrorGetter);
	static NAN_SETTER(onprocessorerrorSetter);
	
	
private:
	
	bool _isDestroyed;
	
	Nan::Persistent<v8::Object> _parameters;
	Nan::Persistent<v8::Object> _port;
	Nan::Persistent<v8::Function> _onprocessorerror;
	
};


#endif // _AUDIO_WORKLET_NODE_HPP_
