#include "FunctionCallMessage.h"

#include "../../../Constants/ProtocolConstants.h"

#include <sstream>

FunctionCallMessage::FunctionCallMessage(const MessageTag &tag, FunctionType function,
                                         std::string serializedMessage)
    : Message(MessageType::Function_Call, tag),
    _functionType(function),
    _serializedMessage(serializedMessage)
{
}

FunctionCallMessage::FunctionCallMessage(const MessageTag &tag, std::string body)
    : Message(MessageType::Function_Call, tag)
{
    auto bodyIntPtr = reinterpret_cast<const int32_t*>(body.data());
    _functionType = static_cast<FunctionType>(bodyIntPtr[0]);
    auto bodyStart = reinterpret_cast<const char*>(bodyIntPtr + 1);
    int messageSize = body.length() - sizeof(int32_t);
    _serializedMessage = std::string(bodyStart, messageSize);
}

FunctionCallMessage::~FunctionCallMessage()
{

}

std::string FunctionCallMessage::serialize()
{
    std::ostringstream stream(std::stringstream::out | std::stringstream::binary);
    stream.write(reinterpret_cast<char*>(&_functionType), sizeof(_functionType));
    std::string serializedFunctionType = stream.str();

    std::string body = serializedFunctionType + _serializedMessage;
    std::string header = Message::serialize(body.length());

    std::string message = header + body;
    return message;
}

