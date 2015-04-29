#pragma once

#include "../Models/RecipientModels/User.h"

#include <memory>
#include <QList>

class Session {
private:
    std::unique_ptr<User> _currentUser;
    QList<User> _onlineUsers;

public:

    std::unique_ptr<User> const &getCurrentUser() const {
        return _currentUser;
    }

    QList<User> onlineUsers() const;
    void insertOnlineUser(User user);
    void removeOnlineUser(User user);
};
