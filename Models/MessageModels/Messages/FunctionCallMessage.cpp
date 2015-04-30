#include "FunctionCallMessage.h"

#include "../../../Constants/ProtocolConstants.h"

FunctionCallMessage::FunctionCallMessage(const MessageTag &tag, FunctionType function,
                                         std::string serializedMessage)
    : Message(MessageType::Function_Call, tag),
    _function(function),
    _serializedMessage(serializedMessage)
{
}

FunctionCallMessage::~FunctionCallMessage()
{

}

std::string FunctionCallMessage::serialize()
{
    return "";
}

