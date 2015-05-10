#ifndef FUNCTIONCALLMESSAGE_H
#define FUNCTIONCALLMESSAGE_H

#include <string>

#include "../Message.h"
#include "../../../Constants/ProtocolConstants.h"

class FunctionCallMessage : public Message
{
public:
    FunctionCallMessage(MessageTag const &tag, FunctionType function, std::string serializedMessage);
    FunctionCallMessage(MessageTag const &tag, std::string body);
    ~FunctionCallMessage();

    std::string serialize();

protected:
    FunctionType _functionType;
    std::string _serializedMessage;
};

#endif // FUNCTIONCALLMESSAGE_H
