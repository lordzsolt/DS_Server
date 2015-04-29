#pragma once

#include <winsock2.h>
#include <string>

typedef void (*MessageSenderCallback)(std::string errorMessage);

class MessageSender {

public:
    MessageSender(SOCKET socket);

    void sendMessage(std::string message) const throw();

private:
    SOCKET _socket;
};