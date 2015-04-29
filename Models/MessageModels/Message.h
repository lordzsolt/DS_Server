#pragma once

#include "../../Constants/ProtocolConstants.h"

#include <string>

class Message {
public:
    Message(MessageType const &type, int32_t index, MessageTag const &tag);

    std::string serialize(int32_t length);
    virtual std::string serialize() = 0;

    static unsigned int headerLength();

    MessageType type() const;
    MessageTag tag() const;
    int32_t index() const;

protected:
    MessageType _type;
    int32_t _index;
    MessageTag _tag;
};
