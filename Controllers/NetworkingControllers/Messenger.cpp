#include "Messenger.h"
#include "../../Factories/SocketFactory.h"

#include "../../Constants/ProtocolConstants.h"
#include "../../Models/MessageModels/Message.h"
#include "../../Models/MessageModels/Messages/LoginMessage.h"
#include "../../Models/MessageModels/Messages/LoginResponseMessage.h"
#include "../../Models/MessageModels/Messages/RegisterMessage.h"
#include "../../Models/MessageModels/Messages/PrivateMessage.h"

#include <iostream>

using namespace std;
using namespace std::placeholders;


Messenger::Messenger(string serverAddress, unsigned short port, MessengerCallback messengerCallback, ConnectionCallback connectionCallback, std::unordered_map<int, Connection> *connections)
    : Messenger(connectionCallback, SocketFactory::createServerSocket(serverAddress, port), connections)
{
    _callbacksByIndex.emplace(0, messengerCallback);
}


Messenger::Messenger(ConnectionCallback connectionCallback, SOCKET socket, std::unordered_map<int, Connection>* connections)
    : _sender(socket),
      _messageReceiver(bind(&Messenger::messageReceived, this, _1)),
      _messageThread(bind(&MessageReceiver::startReceiving, &_messageReceiver)),
      _connectionReceiver(socket, connectionCallback),
      _connectionThread(bind(&ConnectionReceiver::startAcceptingConnections, &_connectionReceiver)),
      _connections(connections)
{
    std::cout << "Messenger started with socket: " << socket << endl;
}


Messenger::~Messenger() {
    _messageReceiver.stopReceiving();
    _messageThread.join();
    _connectionReceiver.stopAcceptingConnections();
    _connectionThread.join();
}


void Messenger::listenToSocket(SOCKET socket)
{
    _messageReceiver.insertSocket(socket);
}


void Messenger::removeSocket(SOCKET socket)
{
    _messageReceiver.removeSocket(socket);
}


void Messenger::sendMessage(Message* message, SOCKET socket, MessengerCallback callback) const {
    _callbacksByIndex.emplace(_messageIndex, callback);
    if (_messageIndex < kMaximumMessageIndex - 1) {
        _messageIndex++;
    }
    else {
        _messageIndex = 0;
    }
    MessageSender sender(socket);
    sender.sendMessage(message->serialize());
}


void Messenger::messageReceived(shared_ptr<Message> message) {
    MessengerCallback callback = _callbacksByIndex[0];
    callback(message);
}
