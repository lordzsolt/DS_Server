#include "ApplicationController.h"

#include "../Models/MessageModels/Message.h"
#include "../Models/RecipientModels/User.h"

#include <iostream>

using namespace std::placeholders;

ApplicationController::ApplicationController()
    : _networking(bind(&ApplicationController::messageReceived, this, _1)),
      _messageHandler(&_networking,
                      &_groups)
{
    srand (time(NULL));
}


ApplicationController& ApplicationController::currentApplication() {
    static ApplicationController instance;
    return instance;
}


const Networking& ApplicationController::networking() const
{
    return _networking;
}

void ApplicationController::messageReceived(std::shared_ptr<Message> message)
{
    std::cout << "Message Type: " << static_cast<int32_t>(message->type()) << std::endl;
    _messageHandler.handleMessage(message.get());

}


void ApplicationController::connectionReceived(SOCKET socket)
{
    int id;
    do {
        id = rand() % 10000;
    } while (_connections.find(id) != _connections.end());

    User newUser(id);
    Connection newConnection(socket, newUser);
    _connections.emplace(id, newConnection);

    _networking.listenToSocket(socket);
}
