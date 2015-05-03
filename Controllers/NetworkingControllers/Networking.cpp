#include "Networking.h"

#include <winsock.h>
#include <functional>

#include "../../Constants/ProtocolConstants.h"
#include "../../Models/MessageModels/Messages/FunctionCallMessage.h"

using namespace std::placeholders;

Networking::Networking(NotificationCallback notificationCallback)
    : Networking(notificationCallback, initializeWSA()) {
}

//_messageReceiver(bind(&Messenger::messageReceived, this, _1, _2)),

Networking::Networking(NotificationCallback callback, nullptr_t t)
    : _messenger(kServerAddress, kServerPort, callback,
                 bind(&Networking::connectionReceived, this, _1))
{
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

void Networking::connectionReceived(SOCKET socket)
{
    listenToSocket(socket);
}


void Networking::listenToSocket(SOCKET socket)
{
    _messenger.listenToSocket(socket);
}


void Networking::removeSocket(SOCKET socket)
{
    _messenger.removeSocket(socket);
}


void Networking::functionMessage(FunctionType functionType,
                     std::string serializedMessage, ArithmeticsCallback callback) const
{
    FunctionCallMessage message(MessageTag::New,
                                functionType,
                                serializedMessage);

    MessengerCallback lamdaCallback = [callback] (std::shared_ptr<Message> message) {
        if (callback) {
            callback("1");
        }
        else {
            std::cerr << "No callback provided";
        }
    };

    _messenger.sendMessage(&message, 0, lamdaCallback);
}

