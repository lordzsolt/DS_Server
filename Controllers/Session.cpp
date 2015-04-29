#include "Session.h"

QList<User> Session::onlineUsers() const
{
    return _onlineUsers;
}


void Session::insertOnlineUser(User user)
{
    _onlineUsers << user;
}


void Session::removeOnlineUser(User user)
{
    _onlineUsers.removeOne(user);
}


