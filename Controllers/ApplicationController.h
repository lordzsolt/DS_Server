#pragma once

#include "Session.h"
#include "NetworkingControllers/Networking.h"
#include "NetworkingControllers/MessageHandler.h"
#include "../Models/NetworkingModels/Connection.h"
#include "../Models/RecipientModels/Group.h"

#include <memory>
#include <unordered_map>

class ApplicationController
{
private:
    //Session _session;
    Networking _networking;
    MessageHandler _messageHandler;
    std::unordered_map<int, Connection> _connections;
    std::unordered_map<int, Group> _groups;

    ApplicationController();
    ApplicationController(ApplicationController const&);
    void operator=(ApplicationController const&);

    void messageReceived(std::shared_ptr<Message> message);
    void connectionReceived(SOCKET socket);

public:
    ~ApplicationController() = default;

    static ApplicationController& currentApplication();

    const Networking& networking() const;
};
