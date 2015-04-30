#include "MessageHandler.h"

MessageHandler::MessageHandler(Networking* networking, std::unordered_map<int, Group>* groups)
    : _networking(networking),
      _groups(groups)
{
}

MessageHandler::~MessageHandler()
{

}

void MessageHandler::handleMessage(Message *message)
{
    std::cout << static_cast<int32_t>(message->tag()) << std::endl;

    switch (message->type()) {
    case MessageType::Log_In: {
//        LoginMessage* loginMessage = dynamic_cast<LoginMessage*>(message);
//        handleLoginMessage(loginMessage);
        break;
    }
    case MessageType::Private_Message: {
//        PrivateMessage* privateMessage = dynamic_cast<PrivateMessage*>(message);
//        handlePrivateMessage(privateMessage);
        break;
    }
    case MessageType::Group_Message: {
//        GroupMessage* groupMessage = dynamic_cast<GroupMessage*>(message);
//        handleGroupMessage(groupMessage);
        break;
    }
//    case MessageType::SumMessage: {
//        SumMessage* sumMessage = dynamic_cast<SumMessage*>(message);
//        handleSumMessage(sumMessage);
//        break;
//    }
    }
}

//void MessageHandler::handleLoginMessage(LoginMessage* message)
//{
//    std::cout << message->username();
//}

//void MessageHandler::handlePrivateMessage(PrivateMessage *message)
//{
//    _networking->privateMessage(*message, nullptr);
//}

//void MessageHandler::handleGroupMessage(GroupMessage *message)
//{
//    auto itGroup = _groups->find(message->recipientId());
//    _networking->groupMessage(*message, itGroup->second, nullptr);
//}
