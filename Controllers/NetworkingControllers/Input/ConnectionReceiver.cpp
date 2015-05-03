#include "ConnectionReceiver.h"

ConnectionReceiver::ConnectionReceiver(SOCKET socket, ConnectionCallback callback, bool startAccepting)
    : _socket(socket),
      _callback(callback)
{
    if (startAccepting) {
        startAcceptingConnections();
    }
}

ConnectionReceiver::~ConnectionReceiver()
{

}

void ConnectionReceiver::startAcceptingConnections()
{
    _shouldAcceptConnections = true;
    awaitConnections();
}

void ConnectionReceiver::stopAcceptingConnections()
{
    _shouldAcceptConnections = false;
}

void ConnectionReceiver::awaitConnections()
{
    if (_shouldAcceptConnections) {
        SOCKET acceptedSocket = accept(_socket, NULL, NULL);
        if (acceptedSocket != INVALID_SOCKET) {
            std::cout << "Connection received: " << acceptedSocket;
            _callback(acceptedSocket);
        }
        awaitConnections();
    }
}

