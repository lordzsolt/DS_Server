#pragma once

#include "Messenger.h"
#include "../../Models/MessageModels/Message.h"
#include "../../Models/MessageModels/Messages/GroupMessage.h"
#include "../../Models/MessageModels/Messages/PrivateMessage.h"
#include "../../Models/RecipientModels/Group.h"

#include <string>
#include <unordered_set>
#include <functional>


using NotificationCallback = std::function<void(std::shared_ptr<Message> message)>;
using NetworkingCallback = std::function<void(bool success)>;
using ArithmeticsCallback = std::function<void(int result)>;

class Networking {
public:

    Networking(NotificationCallback notificationCallback,
               ConnectionCallback connectionCallback,
               std::unordered_map<int, Connection>* connections);

    void listenToSocket(SOCKET socket);
    void removeSocket(SOCKET socket);

    void login(std::string username, std::string password, NetworkingCallback callback) const;
    void loginResponse(std::string username, int userId, NetworkingCallback callback) const;
    void signup(std::string username, std::string password, NetworkingCallback callback) const;
    void privateMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback) const;
    void privateMessage(PrivateMessage message, NetworkingCallback callback);
    void groupMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback) const;
    void groupMessage(GroupMessage message, Group group, NetworkingCallback callback);
    void sumMessage(std::vector<int> elements, ArithmeticsCallback callback);

private:
    Networking(NotificationCallback callback, ConnectionCallback connectionCallback, std::unordered_map<int, Connection>* connections, nullptr_t t);
    nullptr_t initializeWSA();
    Messenger _messenger;
};
