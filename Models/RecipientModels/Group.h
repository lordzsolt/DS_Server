#pragma once

#include "Recipient.h"

#include "User.h"

#include <set>

class Group : public Recipient {
private:
    std::set<User*> _users;

public:

    Group(int id, const std::string& name) : Recipient(id, name) {
    }


    std::set<User *> const &users() const {
        return _users;
    }
};
