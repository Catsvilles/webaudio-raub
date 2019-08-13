#include <cstdlib>


#include "channel-merger-node.hpp"


using namespace v8;
using namespace node;
using namespace std;


// ------ Aux macros

#define THIS_CHANNEL_MERGER_NODE                                                    \
	ChannelMergerNode *channelMergerNode = Nan::ObjectWrap::Unwrap<ChannelMergerNode>(info.This());

#define CACHE_CAS(CACHE, V)                                                   \
	if (this.CACHE == V) {                                           \
		return;                                                               \
	}                                                                         \
	this.CACHE = V;


// ------ Constructor and Destructor

ChannelMergerNode::ChannelMergerNode() :
AudioNode() {
	
	_isDestroyed = false;
	
}


ChannelMergerNode::~ChannelMergerNode() {
	
	_destroy();
	
}


void ChannelMergerNode::_destroy() { DES_CHECK;
	
	_isDestroyed = true;
	
	AudioNode::_destroy();
	
}


// ------ Methods and props




// ------ System methods and props for ObjectWrap

V8_STORE_FT ChannelMergerNode::_protoChannelMergerNode;
V8_STORE_FUNC ChannelMergerNode::_ctorChannelMergerNode;


void ChannelMergerNode::init(Napi::Object target) {
	
	V8_VAR_FT proto = Nan::New<FunctionTemplate>(newCtor);

	// class ChannelMergerNode inherits AudioNode
	V8_VAR_FT parent = Nan::New(AudioNode::_protoAudioNode);
	proto->Inherit(parent);
	
	proto->InstanceTemplate()->SetInternalFieldCount(1);
	proto->SetClassName(JS_STR("ChannelMergerNode"));
	
	
	// Accessors
	V8_VAR_OT obj = proto->PrototypeTemplate();
	ACCESSOR_R(obj, isDestroyed);
	
	
	
	// -------- dynamic
	
	Nan::SetPrototypeMethod(proto, "destroy", destroy);
	
	
	
	// -------- static
	
	V8_VAR_FUNC ctor = Nan::GetFunction(proto).ToLocalChecked();
	
	_protoChannelMergerNode.Reset(proto);
	_ctorChannelMergerNode.Reset(ctor);
	
	Nan::Set(target, JS_STR("ChannelMergerNode"), ctor);
	
	
}


bool ChannelMergerNode::isChannelMergerNode(Napi::Object obj) {
	return Nan::New(_protoChannelMergerNode)->HasInstance(obj);
}


Napi::Object ChannelMergerNode::getNew() {
	
	V8_VAR_FUNC ctor = Nan::New(_ctorChannelMergerNode);
	// V8_VAR_VAL argv[] = { /* arg1, arg2, ... */ };
	return Nan::NewInstance(ctor, 0/*argc*/, nullptr/*argv*/).ToLocalChecked();
	
}


NAN_METHOD(ChannelMergerNode::newCtor) {
	
	CTOR_CHECK("ChannelMergerNode");
	
	ChannelMergerNode *channelMergerNode = new ChannelMergerNode();
	channelMergerNode->Wrap(info.This());
	
	RET_VALUE(info.This());
	
}


NAN_METHOD(ChannelMergerNode::destroy) { THIS_CHANNEL_MERGER_NODE; THIS_CHECK;
	
	channelMergerNode->emit("destroy");
	
	channelMergerNode->_destroy();
	
}


NAN_GETTER(ChannelMergerNode::isDestroyedGetter) { THIS_CHANNEL_MERGER_NODE;
	
	RET_BOOL(channelMergerNode->_isDestroyed);
	
}
