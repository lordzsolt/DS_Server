#include "LoginMessage.h"

#include "../../../Constants/ProtocolConstants.h"

#include <sstream>
#include <boost/tokenizer.hpp>

//using namespace std;
//using namespace boost;

//LoginMessage::LoginMessage(int index, MessageTag const &tag, std::string &username, std::string &password)
//        : Message(MessageType::Log_In, index, tag), _username(username), _password(password)
//{
//}


//LoginMessage::LoginMessage(int index, MessageTag const &tag, std::string &body)
//        : Message(MessageType::Log_In, index, tag)
//{
//    char_separator<char> separator("&");
//    tokenizer<char_separator<char>> tokens(body, separator);

//    for (const auto& t : tokens) {
//        char_separator<char> innerSeparator("=");
//        tokenizer<char_separator<char>> innerTokens(t, innerSeparator);
//        vector<string> innerStrings(innerTokens.begin(), innerTokens.end());

//        string key = innerStrings[0];
//        string value = innerStrings[1];

//        if (t == kMessageKeyUsername) {
//            _username = t;
//        }
//        else if (t == kMessageKeyPassword) {
//            _password = t;
//        }
//    }
//}


//std::string LoginMessage::serialize() {
//    std::ostringstream bodyStream;
//    if (_username.length()) {
//        bodyStream << kMessageKeyUsername << "=" << _username;
//    }
//    bodyStream << "&";
//    if (_password.length()) {
//        bodyStream << kMessageKeyPassword << "=" << _password;
//    }
//    std::string body = bodyStream.str();

//    std::string header = Message::serialize(body.length());

//    std::string message = header + body;
//    return message;
//}
//std::string LoginMessage::username() const
//{
//    return _username;
//}

