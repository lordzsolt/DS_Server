#ifndef CONNECTIONRECEIVER_H
#define CONNECTIONRECEIVER_H

#include <functional>
#include <WinSock2.h>

using ConnectionReceiverCallback = std::function<void(SOCKET socket)>;

class ConnectionReceiver
{
public:
    ConnectionReceiver(SOCKET socket, ConnectionReceiverCallback callback);
    ~ConnectionReceiver();

    void startAcceptingConnections();
    void stopAcceptingConnections();

private:
    SOCKET _socket;
    ConnectionReceiverCallback _callback;

    bool _shouldAcceptConnections;
    void awaitConnections();
};

#endif // CONNECTIONRECEIVER_H
