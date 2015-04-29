#ifndef MESSAGEDESERIALIZER_H
#define MESSAGEDESERIALIZER_H

#include "../Message.h"

#include <string>
#include <memory>
#include <type_traits>

enum class ValueType : int32_t {
    Undefined,
    Bool,
    Int,
    Float,
    Double
};


class MessageDeserializer {
public:
    static std::shared_ptr<Message> deserializeMessage(std::string header, std::string body);
    static ValueType idOfType(const std::type_info &ti);
};

#endif //MESSAGEDESERIALIZER_H
