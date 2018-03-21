#ifndef _AUDIO_TIMESTAMP_HPP_
#define _AUDIO_TIMESTAMP_HPP_


#include <addon-tools.hpp>


class AudioTimestamp : public Nan::ObjectWrap {
	
public:
	
	// Public V8 init
	static void init(v8::Local<v8::Object> target);
	
	void _destroy();
	
	
// Methods and props
protected:
	
	AudioTimestamp();
	virtual ~AudioTimestamp();
	
	static Nan::Persistent<v8::FunctionTemplate> _protoAudioTimestamp; // for inheritance
	static Nan::Persistent<v8::Function> _ctorAudioTimestamp;
	
	
// System methods and props for ObjectWrap
private:
	
	static NAN_METHOD(newCtor);
	
	static NAN_METHOD(destroy);
	static NAN_GETTER(isDestroyedGetter);
	
	
	
	static NAN_GETTER(contextTimeGetter);
	static NAN_SETTER(contextTimeSetter);
	
	static NAN_GETTER(performanceTimeGetter);
	static NAN_SETTER(performanceTimeSetter);
	
	
private:
	
	bool _isDestroyed;
	
	double _contextTime;
	double _performanceTime;
	
};


#endif // _AUDIO_TIMESTAMP_HPP_
