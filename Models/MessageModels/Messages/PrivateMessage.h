#pragma once

#include "../Message.h"

#include <string>

enum class MessageTag : int;

//class PrivateMessage : public Message {
//public:

//    PrivateMessage(int index, MessageTag const &tag, const int recipientId, const std::string &message);

//    std::string serialize();

//    int getRecipientId() const;
//    void setRecipientId(int value);

//protected:
//    int recipientId;
//    std::string message;
//};
