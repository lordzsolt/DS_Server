#include "FunctionCallMessage.h"

#include "../../../Constants/ProtocolConstants.h"

FunctionCallMessage::FunctionCallMessage(const MessageTag &tag, int function,
                                         std::string serializedMessage)
    : Message(MessageType::Function_Call, tag),
    _function(function),
    _serializedMessage(serializedMessage)
{
}

FunctionCallMessage::~FunctionCallMessage()
{

}
