#ifndef CONNECTION_H
#define CONNECTION_H

#include "../RecipientModels/Recipient.h"

#include <WinSock2.h>

class Connection
{
public:
    Connection(SOCKET socket, Recipient recipient);
    ~Connection();

    SOCKET socket() const;
    void setSocket(const SOCKET &socket);

    Recipient recipient() const;
    void setRecipient(const Recipient &recipient);

private:
    SOCKET _socket;
    Recipient _recipient;
};

#endif // CONNECTION_H
