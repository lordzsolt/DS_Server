#ifndef CONNECTIONRECEIVER_H
#define CONNECTIONRECEIVER_H

#include <functional>
#include <WinSock2.h>

using ConnectionCallback = std::function<void(SOCKET socket)>;

class ConnectionReceiver
{
public:
    ConnectionReceiver(SOCKET socket, ConnectionCallback callback);
    ~ConnectionReceiver();

    void startAcceptingConnections();
    void stopAcceptingConnections();

private:
    SOCKET _socket;
    ConnectionCallback _callback;

    bool _shouldAcceptConnections;
    void awaitConnections();
};

#endif // CONNECTIONRECEIVER_H
