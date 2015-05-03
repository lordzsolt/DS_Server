#pragma once

#include "Output/MessageSender.h"
#include "Input/MessageReceiver.h"
#include "Input/ConnectionReceiver.h"

#include "../../Models/MessageModels/Message.h"
#include "../../Models/MessageModels/Messages/PrivateMessage.h"
#include "../../Models/MessageModels/Messages/GroupMessage.h"
//#include "../../Models/MessageModels/Messages/ArithmeticMessages/SumMessage.h"
#include "../../Models/NetworkingModels/Connection.h"

#include "../../Models/RecipientModels/Group.h"

#include "../../Constants/ProtocolConstants.h"

#include <unordered_set>
#include <functional>
#include <unordered_map>
#include <thread>
#include <memory>

using MessengerCallback = std::function<void(std::shared_ptr<Message>)>;

class Messenger {
public:
    Messenger(std::string serverAddress,
              unsigned short port,
              MessengerCallback messengerCallback,
              ConnectionCallback connectionCallback);

    virtual ~Messenger();

    void listenToSocket(SOCKET socket);
    void removeSocket(SOCKET socket);

    void sendMessage(Message* message, SOCKET socket, MessengerCallback callback) const;

private:
    MessageSender _sender;
    MessageReceiver _messageReceiver;
    ConnectionReceiver _connectionReceiver;
    std::thread _messageThread;
    std::thread _connectionThread;
    mutable unsigned int _messageIndex = 1;

    /**
     * @brief _callbacksByIndex
     * Contains the callbacks provided, the callback provided in the constructor will always be at index 0
     */
    mutable std::unordered_map<unsigned int, MessengerCallback> _callbacksByIndex;

    Messenger(SOCKET socket, ConnectionCallback connectionCallback);
    void messageReceived(int32_t index, std::shared_ptr<Message> message);
};
