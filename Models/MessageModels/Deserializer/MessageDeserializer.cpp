#include "MessageDeserializer.h"

#include "../../../Constants/ProtocolConstants.h"
#include "../Messages/FunctionCallMessage.h"
#include "../Messages/LoginMessage.h"

using namespace std;

shared_ptr<Message> MessageDeserializer::deserializeMessage(std::string header, std::string body) {
    auto headerIntPtr = reinterpret_cast<const int32_t*>(header.data());

    int32_t type = headerIntPtr[2];
    int32_t tag = headerIntPtr[3];

    MessageType messageType = static_cast<MessageType>(type);
    switch (messageType) {
        case MessageType::Log_In: {
//            LoginMessage loginMessage(index, static_cast<MessageTag>(tag), body);
//            return make_shared<LoginMessage>(loginMessage);
            break;
        }
        case MessageType::Register: {
            break;
        }
        case MessageType::Private_Message: {
            break;
        }
        case MessageType::Group_Message: {
            break;
        }
        case MessageType::Function_Call: {
            FunctionCallMessage message(static_cast<MessageTag>(tag), body);
            return make_shared<FunctionCallMessage>(message);
        }
        default: {
            return nullptr;
            std::cout << "Unknown message type: " << (int)messageType;
            //TODO: Throw an exception
        }
    }
}

ValueType MessageDeserializer::idOfType(const type_info &ti)
{
    if (ti == typeid(bool)) {
        return ValueType::Bool;
    }
    if (ti == typeid(int)) {
        return ValueType::Int;
    }
    if (ti == typeid(float)) {
        return ValueType::Float;
    }
    if (ti == typeid(double)) {
        return ValueType::Double;
    }

    return ValueType::Undefined;
}
