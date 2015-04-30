#pragma once

#include <winsock2.h>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <mutex>

using SocketListenerCallback = std::function<void(int32_t index,
                                                  std::string header, std::string message)>;

class SocketListener {

public:
    SocketListener(SocketListenerCallback callback, unsigned int headerLength);

    void startListening();
    void stopListening();

    void insertSocket(SOCKET socket);
    void removeSocket(SOCKET socket);

private:

    class SocketInfo {
    public:
        int32_t index;
        bool waitingForWholeMessage;
        std::string header;
        std::string body;
        int32_t expectedLength;
    };

    std::mutex _socketsMutex;
    std::unordered_set<SOCKET> _sockets;
    std::unordered_map<SOCKET, SocketInfo> _socketInfo;

    SocketListenerCallback _callback;
    unsigned int _headerLength;
    bool _listen = false; //Should be atomic...

    void listen();
    void readSocket(SOCKET socket);
    void readNewMessageFromSocket(SOCKET socket);
    void appendCurrentMessageFromSocket(std::pair<SOCKET, SocketInfo> socketDescriptor);
    void wholeMessageArrived(std::pair<SOCKET, SocketInfo> socketDescriptor);
};
