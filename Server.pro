#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T20:21:50
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Server
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app

PRECOMPILED_HEADER = _pch.h

#Boost
INCLUDEPATH += C:/Development/boost/boost_1_58_0
LIBS += "-LC:/Development/boost/boost_1_58_0/libs"

#Winsocket
LIBS += -lws2_32

SOURCES += main.cpp \
    Constants/ProtocolConstants.cpp \
    Controllers/NetworkingControllers/Input/ConnectionReceiver.cpp \
    Controllers/NetworkingControllers/Input/MessageReceiver.cpp \
    Controllers/NetworkingControllers/Input/SocketListener.cpp \
    Controllers/NetworkingControllers/Output/MessageSender.cpp \
    Controllers/NetworkingControllers/MessageHandler.cpp \
    Controllers/NetworkingControllers/Messenger.cpp \
    Controllers/NetworkingControllers/Networking.cpp \
    Controllers/ApplicationController.cpp \
    Controllers/Session.cpp \
    Factories/SocketFactory.cpp \
    Models/MessageModels/Deserializer/MessageDeserializer.cpp \
    Models/MessageModels/Messages/GroupMessage.cpp \
    Models/MessageModels/Messages/LoginMessage.cpp \
    Models/MessageModels/Messages/LoginResponseMessage.cpp \
    Models/MessageModels/Messages/PrivateMessage.cpp \
    Models/MessageModels/Messages/RegisterMessage.cpp \
    Models/MessageModels/Message.cpp \
    Models/NetworkingModels/Connection.cpp \
    Models/NetworkingModels/ErrorMessage.cpp \
    Models/RecipientModels/Group.cpp \
    Models/RecipientModels/User.cpp

HEADERS += \
    Constants/ProtocolConstants.h \
    Controllers/NetworkingControllers/Input/ConnectionReceiver.h \
    Controllers/NetworkingControllers/Input/MessageReceiver.h \
    Controllers/NetworkingControllers/Input/SocketListener.h \
    Controllers/NetworkingControllers/Output/MessageSender.h \
    Controllers/NetworkingControllers/MessageHandler.h \
    Controllers/NetworkingControllers/Messenger.h \
    Controllers/NetworkingControllers/Networking.h \
    Controllers/ApplicationController.h \
    Controllers/Session.h \
    Factories/SocketFactory.h \
    Models/MessageModels/Deserializer/MessageDeserializer.h \
    Models/MessageModels/Messages/GroupMessage.h \
    Models/MessageModels/Messages/LoginMessage.h \
    Models/MessageModels/Messages/LoginResponseMessage.h \
    Models/MessageModels/Messages/PrivateMessage.h \
    Models/MessageModels/Messages/RegisterMessage.h \
    Models/MessageModels/Message.h \
    Models/NetworkingModels/Connection.h \
    Models/NetworkingModels/ErrorMessage.h \
    Models/RecipientModels/Group.h \
    Models/RecipientModels/Recipient.h \
    Models/RecipientModels/User.h
