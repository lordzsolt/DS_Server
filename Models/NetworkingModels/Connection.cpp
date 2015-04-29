#include "Connection.h"

Connection::Connection(SOCKET socket, Recipient recipient)
    : _socket(socket),
      _recipient(recipient)
{

}

Connection::~Connection()
{

}
SOCKET Connection::socket() const
{
    return _socket;
}

void Connection::setSocket(const SOCKET &socket)
{
    _socket = socket;
}
Recipient Connection::recipient() const
{
    return _recipient;
}

void Connection::setRecipient(const Recipient &recipient)
{
    _recipient = recipient;
}



