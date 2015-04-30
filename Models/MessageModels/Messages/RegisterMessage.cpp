#include "RegisterMessage.h"

#include "../../../Constants/ProtocolConstants.h"

#include <sstream>

//RegisterMessage::RegisterMessage(int index, MessageTag const &tag, std::string &username, std::string &password)
//        : Message(MessageType::Register, index, tag), username(username), password(password) {
//}


//std::string RegisterMessage::serialize() {
//    std::ostringstream bodyStream;
//    bodyStream << kMessageKeyUsername << "=" << username;
//    bodyStream << "&";
//    bodyStream << kMessageKeyPassword << "=" << password;
//    std::string body = bodyStream.str();

//    std::string header = Message::serialize(body.length());
//    std::string message = header + body;
//    return message;
//}
