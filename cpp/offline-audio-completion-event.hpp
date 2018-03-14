#ifndef _OFFLINE_AUDIO_COMPLETION_EVENT_HPP_
#define _OFFLINE_AUDIO_COMPLETION_EVENT_HPP_


#include <addon-tools.hpp>


class OfflineAudioCompletionEvent : public Nan::ObjectWrap {
	
// Public V8 init
public:
	
	static void init(v8::Local<v8::Object> target);
	
	
// Public C++ methods: in-engine calls
public:
	
	
// Protected C++ methods: implementing JS calls
protected:
	
	OfflineAudioCompletionEvent();
	virtual ~OfflineAudioCompletionEvent();
	
	
// JS methods and props
protected:
	
	static NAN_METHOD(newCtor);
	
	static NAN_METHOD(destroy);
	
	
	
	
	static NAN_GETTER(isDestroyedGetter);
	
	
	static NAN_GETTER(renderedBufferGetter);
	
	
// Actual destruction-handler
private:
	
	void _destroy();
	
	
// Stored JS constructor and helpers
private:
	
	static Nan::Persistent<v8::Function> _constructor;
	
	
// This-state storage
private:
	
	bool _isDestroyed;
	
	Nan::Persistent<v8::Object> _renderedBuffer;
	
};


#endif // _OFFLINE_AUDIO_COMPLETION_EVENT_HPP_