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



void Messenger::sendLogin(std::string username, std::string password, MessengerCallback callback) const {
    LoginMessage loginMessage(_messageIndex, MessageTag::New, username, password);
    sendMessage(&loginMessage, 0, callback);
}

void Messenger::sendLoginResponse(string username, int userId, MessengerCallback callback) const
{
//    LoginResponseMessage responseMessage(_messageIndex, MessageTag::Acknowledge);
//    auto itConnection = _connections->find(message.getRecipientId());
//    if (itConnection != _connections->end()) {
//        sendMessage(&responseMessage, itConnection->second.socket(), callback);
//    }
}


void Messenger::sendSignup(std::string username, std::string password, MessengerCallback callback) const {
    RegisterMessage registerMessage(_messageIndex, MessageTag::New, username, password);
    sendMessage(&registerMessage, 0, callback);
}


void Messenger::sendPrivateMessage(std::string message, int recipientId, MessengerCallback callback) const {
    PrivateMessage privateMessage(_messageIndex, MessageTag::New, recipientId, message);
    sendPrivateMessage(privateMessage, callback);
}


void Messenger::sendPrivateMessage(PrivateMessage message,  MessengerCallback callback) const
{
    auto itConnection = _connections->find(message.getRecipientId());
    if (itConnection != _connections->end()) {
        sendMessage(&message, itConnection->second.socket(), callback);
    }
    else {
        auto anyConnection = _connections->begin();
        sendMessage(&message, anyConnection->second.socket(), callback);
    }
}


void Messenger::sendGroupMessage(std::string message, std::unordered_set<int> recipientIds, MessengerCallback callback) const {
}

void Messenger::sendGroupMessage(GroupMessage message, Group group, MessengerCallback callback) const
{
    for (auto user : group.users()) {
        auto itConnection = _connections->find(user->getId());
        if (itConnection != _connections->end()) {
            sendMessage(&message, itConnection->second.socket(), callback);
        }
    }
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
