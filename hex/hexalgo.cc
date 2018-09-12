#include <node.h>
#include <node_buffer.h>
#include "hex.h"

using namespace v8;

void Hash(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    if (args.Length() != 1)
    {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }
    Local<Object> bufferObj = args[0]->ToObject();
    char *bufferData = node::Buffer::Data(bufferObj);
    char *result = (char *)malloc(sizeof(char) * 32);
    
    hex_hash(bufferData, result);
    Local<Object> buf;
    if (node::Buffer::New(isolate, result, sizeof(char) * 32).ToLocal(&buf))
    {
        args.GetReturnValue().Set(buf);
    }
    else
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Cannot create buffer")));
    }
    
}
void Init(Handle<Object> exports)
{
    NODE_SET_METHOD(exports, "Hash", Hash);
}
NODE_MODULE(addon, Init)