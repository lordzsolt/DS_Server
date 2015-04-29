#include "MessageReceiver.h"

#include "../../../Models/MessageModels/Deserializer/MessageDeserializer.h"

using namespace std;
using namespace std::placeholders;

MessageReceiver::MessageReceiver(MessageReceiverCallback callback)
        : _listener(bind(&MessageReceiver::messageReceived, this, _1, _2), Message::headerLength()),
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


void MessageReceiver::messageReceived(string header, string body) {
    shared_ptr<Message> message = MessageDeserializer::deserializeMessage(header, body);
    _callback(message);
}
