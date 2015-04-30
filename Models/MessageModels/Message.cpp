#include "Message.h"
#include "../../Constants/ProtocolConstants.h"

#include <sstream>

Message::Message(MessageType const &type, MessageTag const &tag)
    : _type(type),
      _tag(tag)
{
}


/**
* If Message::serialize is changed, Message::headerLength must be updated
*   ExpectedMessageLength must be updated in SocketListener
*   MessageDeserializer must be updated
*   So f*ck you for changing it...
*/
std::string Message::serialize(int32_t length) {
    std::ostringstream stream(std::stringstream::out | std::stringstream::binary);

    stream.write(reinterpret_cast<char*>(&length), sizeof(length));
    int32_t messageType = static_cast<int32_t>(_type);
    stream.write(reinterpret_cast<char*>(&messageType), sizeof(messageType));
    int32_t messageTag = static_cast<int32_t>(_tag);
    stream.write(reinterpret_cast<char*>(&messageTag), sizeof(messageTag));

    return stream.str();
}


unsigned int Message::headerLength()
{
    return 3 * sizeof(int32_t);
}


MessageType Message::type() const
{
    return _type;
}
MessageTag Message::tag() const
{
    return _tag;
}


