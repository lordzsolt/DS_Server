#include "PrivateMessage.h"

#include "../../../Constants/ProtocolConstants.h"

#include <sstream>

//PrivateMessage::PrivateMessage(int index, MessageTag const &tag, const int recipientId, const std::string &message)
//        : Message(MessageType::Private_Message, index, tag), recipientId(recipientId), message(message) {
//}

//std::string PrivateMessage::serialize() {
//    std::ostringstream bodyStream;
//    bodyStream << kMessageKeyRecipientId << "=" << recipientId;
//    bodyStream << "&";
//    bodyStream << kMessageKeyMessage << "=" << message;
//    std::string body = bodyStream.str();

//    std::string header = Message::serialize(body.length());
//    std::string message = header + body;
//    return message;
//}
//int PrivateMessage::getRecipientId() const
//{
//    return recipientId;
//}

//void PrivateMessage::setRecipientId(int value)
//{
//    recipientId = value;
//}
