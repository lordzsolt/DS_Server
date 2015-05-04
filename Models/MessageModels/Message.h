#pragma once

#include "../../Constants/ProtocolConstants.h"

#include <string>

class Message {
public:
    Message(MessageType const &type, MessageTag const &tag);

    std::string serialize(int32_t length);
    virtual std::string serialize() = 0;

    static unsigned int headerLength();

    MessageType type() const;
    MessageTag tag() const;

protected:
    MessageType _type;
    MessageTag _tag;
};
