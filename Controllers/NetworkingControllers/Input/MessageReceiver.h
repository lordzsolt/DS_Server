#include "SocketListener.h"

#include "../../../Models/MessageModels/Message.h"

#include <functional>
#include <memory>

using MessageReceiverCallback = std::function<void(std::shared_ptr<Message> message)>;

class MessageReceiver {
public:
    MessageReceiver(MessageReceiverCallback callback);

    void startReceiving();
    void stopReceiving();

    void insertSocket(SOCKET socket);
    void removeSocket(SOCKET socket);
private:
    SocketListener _listener;
    MessageReceiverCallback _callback;

    void messageReceived(std::string header, std::string body);
};
