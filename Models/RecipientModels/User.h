#pragma once

#include "Recipient.h"

#include <vector>

class User : public Recipient {
private:
    std::vector<User> friends;

public:
    User(int id) : Recipient(id) {

    }
    User(int id, const std::string& name) : Recipient(id, name) {
    }

};
