#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "Networking.h"

#include "../../Models/MessageModels/Message.h"
#include "../../Models/MessageModels/Messages/LoginMessage.h"
#include "../../Models/MessageModels/Messages/PrivateMessage.h"
#include "../../Models/MessageModels/Messages/GroupMessage.h"
//#include "../../Models/MessageModels/Messages/ArithmeticMessages/SumMessage.h"


class MessageHandler
{
public:
    MessageHandler(Networking *networking,
                   std::unordered_map<int, Group> *groups);
    ~MessageHandler();

    void handleMessage(Message *message);

private:
    Networking* _networking;
    std::unordered_map<int, Group>* _groups;

//    void handleLoginMessage(LoginMessage* message);
//    void handlePrivateMessage(PrivateMessage* message);
//    void handleGroupMessage(GroupMessage* message);

};

#endif // MESSAGEHANDLER_H
