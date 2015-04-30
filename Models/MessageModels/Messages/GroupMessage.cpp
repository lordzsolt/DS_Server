//#include "GroupMessage.h"

//#include "../../../Constants/ProtocolConstants.h"

//#include <sstream>

//GroupMessage::GroupMessage(MessageTag const &tag, const int recipientId, const std::string &message)
//        : Message(MessageType::Group_Message, tag), _recipientId(recipientId), message(message) {
//}

//std::string GroupMessage::serialize() {
//    std::ostringstream bodyStream;
//    bodyStream << kMessageKeyRecipientId << "=" << _recipientId;
//    bodyStream << "&";
//    bodyStream << kMessageKeyMessage << "=" << message;
//    std::string body = bodyStream.str();

//    std::string header = Message::serialize(body.length());
//    std::string message = header + body;
//    return message;
//}
//int GroupMessage::recipientId() const
//{
//    return _recipientId;
//}
