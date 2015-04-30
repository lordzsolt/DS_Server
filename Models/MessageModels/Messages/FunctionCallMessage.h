#ifndef FUNCTIONCALLMESSAGE_H
#define FUNCTIONCALLMESSAGE_H

#include <string>

#include "../Message.h"


class FunctionCallMessage : public Message
{
public:
    FunctionCallMessage(MessageTag const &tag, int function, std::string serializedMessage);
    ~FunctionCallMessage();

protected:
    int _function;
    std::string _serializedMessage;
};

#endif // FUNCTIONCALLMESSAGE_H
