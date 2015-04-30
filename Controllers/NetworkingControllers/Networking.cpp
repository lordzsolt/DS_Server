#include "Networking.h"

#include <winsock.h>
#include <functional>

#include "../../Constants/ProtocolConstants.h"
#include "../../Models/MessageModels/Messages/FunctionCallMessage.h"

Networking::Networking(NotificationCallback notificationCallback)
    : Networking(notificationCallback, initializeWSA()) {
}

Networking::Networking(NotificationCallback callback, nullptr_t t)
    : _messenger(kServerAddress, kServerPort, callback) {
    std::cout << "Networking started with: " << kServerAddress << ":" << kServerPort << "\n";
}


nullptr_t Networking::initializeWSA() {
    int iResult;
    WSADATA wsaData;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %d\n", iResult);
    }
    return nullptr;
}


void Networking::listenToSocket(SOCKET socket)
{
    _messenger.listenToSocket(socket);
}

void Networking::removeSocket(SOCKET socket)
{
    _messenger.removeSocket(socket);
}

//void Networking::login(std::string username, std::string password, NetworkingCallback callback) const {
////    MessengerCallback lamdaCallback = [callback] (std::shared_ptr<Message> message) {
////        if (callback) {
////            callback(true);
////        }
////        else {
////            std::cerr << "No callback provided";
////        }
////    };
////    _messenger.sendLogin(username, password, lamdaCallback);
//}

//void Networking::loginResponse(std::string username, int userId, NetworkingCallback callback) const
//{
////    MessengerCallback lamdaCallback = [callback] (std::shared_ptr<Message> message) {
////        if (callback) {
////            callback(true);
////        }
////        else {
////            std::cerr << "No callback provided";
////        }
////    };
////    _messenger.sendLoginResponse(username, userId, lamdaCallback);
//}


//void Networking::signup(std::string username, std::string password, NetworkingCallback callback) const {

//}


//void Networking::privateMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback) const {
////    MessengerCallback lamdaCallback = [callback] (std::shared_ptr<Message> message) {
////        if (callback) {
////            callback(true);
////        }
////        else {
////            std::cerr << "No callback provided";
////        }
////    };
////    _messenger.sendPrivateMessage(message, *recipientIds.begin(), lamdaCallback);
//}

//void Networking::privateMessage(PrivateMessage message, NetworkingCallback callback)
//{
////    _messenger.sendPrivateMessage(message, nullptr);
//}


//void Networking::groupMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback) const {
////    MessengerCallback lamdaCallback = [callback] (std::shared_ptr<Message> message) {
////        if (callback) {
////            callback(true);
////        }
////        else {
////            std::cerr << "No callback provided";
////        }
////    };
////    _messenger.sendGroupMessage(message, recipientIds, lamdaCallback);
//}


//void Networking::groupMessage(GroupMessage message, Group group, NetworkingCallback callback)
//{
////    MessengerCallback lamdaCallback = [callback] (std::shared_ptr<Message> message) {
////        if (callback) {
////            callback(true);
////        }
////        else {
////            std::cerr << "No callback provided";
////        }
////    };

////    _messenger.sendGroupMessage(message, group, lamdaCallback);
//}


void Networking::functionMessage(FunctionType functionType,
                     std::string serializedMessage, ArithmeticsCallback callback)
{
    FunctionCallMessage message(MessageTag::New,
                                functionType,
                                serializedMessage);
    _messenger.sendMessage(&message, 0, nullptr);
}

