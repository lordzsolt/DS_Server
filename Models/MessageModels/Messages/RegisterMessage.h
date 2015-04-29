#pragma once

#include "../Message.h"

#include <string>

enum class MessageTag : int;

class RegisterMessage : public Message {
public:

    RegisterMessage(int index, MessageTag const &tag, std::string &username, std::string &password);

    std::string serialize();

protected:
    std::string username;
    std::string password;
};