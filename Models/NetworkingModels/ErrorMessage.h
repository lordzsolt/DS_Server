#pragma once

#include <string>

class ErrorMessage {
private:
    int _code;
    std::string _message;
public:
    ErrorMessage(std::string &_message, int _code);

    int get_code() const {
        return _code;
    }

    const std::string &get_message() const {
        return _message;
    }
};