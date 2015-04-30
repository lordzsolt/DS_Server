#include "SocketListener.h"

#include <sstream>
#include <vector>

using namespace std;

SocketListener::SocketListener(SocketListenerCallback callback, unsigned int headerLength)
        : _callback(callback),
          _headerLength(headerLength)
{
}


void SocketListener::stopListening() {
    printf("Listening stopped");
    _listen = false;
}

void SocketListener::insertSocket(SOCKET socket)
{
    _socketsMutex.lock();
    _sockets.insert(socket);
    _socketsMutex.unlock();
}

void SocketListener::removeSocket(SOCKET socket)
{
    _socketsMutex.lock();
    _sockets.erase(socket);
    _socketsMutex.unlock();
}


void SocketListener::startListening() {
    _listen = true;
    listen();
}


void SocketListener::listen () {

    if (!_listen) {
        return;
    }

    if (_sockets.size() == 0) {
        Sleep(1000);
        listen();
        return;
    }

    fd_set readfds;
    struct timeval timeValues;

    //clear the set
    FD_ZERO(&readfds);
    // add our descriptors to the set
    for (SOCKET socket : _sockets) {
        FD_SET(socket, &readfds);
    }

    timeValues.tv_sec = 10;
    timeValues.tv_usec = 500000;
    int iResult = select(0, &readfds, NULL, NULL, &timeValues);

    if (iResult == SOCKET_ERROR) {
        wprintf(L"Select failed with error: %d\n",WSAGetLastError());
    }
    else {
        if (iResult == 0) {
            printf("Timeout occurred!  No data after 10.5 seconds.\n");
        }
        else {
            for (SOCKET socket : _sockets) {
                if (FD_ISSET(socket, &readfds)) {
                    readSocket(socket);
                }
            }
        }
        listen();
    }
}


void SocketListener::readSocket(SOCKET socket) {
    auto socketDescriptor = _socketInfo.find(socket);
    if (socketDescriptor == _socketInfo.end()) {
        //This is a new message
        readNewMessageFromSocket(socket);
    }
    else {
        //This is the other half of the previous message (stored in _body)
        appendCurrentMessageFromSocket(*socketDescriptor);
    }
}


void SocketListener::readNewMessageFromSocket(SOCKET socket) {
    SocketInfo currentSocketInfo;
    currentSocketInfo.header.resize(_headerLength);
    int iResult = recv(socket, &currentSocketInfo.header[0], _headerLength, 0);
    if (iResult == SOCKET_ERROR) {
        //wprintf(L"recv failed with error: %d\n", WSAGetLastError());
    }

    auto headerIntPtr = reinterpret_cast<const int32_t*>(currentSocketInfo.header.data());

    currentSocketInfo.index = headerIntPtr[0];
    currentSocketInfo.expectedLength = headerIntPtr[1];

    currentSocketInfo.body.resize(currentSocketInfo.expectedLength);

    _socketInfo.emplace(socket, currentSocketInfo);
    appendCurrentMessageFromSocket(make_pair(socket, currentSocketInfo));
}


void SocketListener::appendCurrentMessageFromSocket(pair<SOCKET, SocketInfo> socketDescriptor) {
    int iResult = recv(socketDescriptor.first, &socketDescriptor.second.body[0],
            socketDescriptor.second.expectedLength, MSG_WAITALL);
    if (iResult == SOCKET_ERROR) {
        //wprintf(L"recv failed with error: %d\n", WSAGetLastError());
    }
    else {
        wholeMessageArrived(socketDescriptor);
    }
}


void SocketListener::wholeMessageArrived(pair<SOCKET, SocketInfo> socketDescriptor) {
    socketDescriptor.second.waitingForWholeMessage = false;

    _callback(0, socketDescriptor.second.header, socketDescriptor.second.body);
    _socketInfo.erase(socketDescriptor.first);
}
