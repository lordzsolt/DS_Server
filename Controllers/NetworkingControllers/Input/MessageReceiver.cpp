#include "MessageReceiver.h"

#include "../../../Models/MessageModels/Deserializer/MessageDeserializer.h"

using namespace std;
using namespace std::placeholders;

//TODO: Refactor Listener.headerLength to more easily understand why it's
//Message::headerLength() + sizeof(int32_t))
//Currently it's because Messenger adds an index (sizeof(int32_t)) infront of
//the actual message.
MessageReceiver::MessageReceiver(MessageReceiverCallback callback)
        : _listener(bind(&MessageReceiver::messageReceived, this, _1, _2, _3),
                    Message::headerLength() + sizeof(int32_t)),
          _callback(callback)
{

}

void MessageReceiver::startReceiving() {
    _listener.startListening();
}

void MessageReceiver::stopReceiving() {
    _listener.stopListening();
}

void MessageReceiver::insertSocket(SOCKET socket)
{
    _listener.insertSocket(socket);
}

void MessageReceiver::removeSocket(SOCKET socket)
{
    _listener.removeSocket(socket);
}


void MessageReceiver::messageReceived(int32_t index, string header, string body) {
    shared_ptr<Message> message = MessageDeserializer::deserializeMessage(header, body);
    _callback(index, message);
}
