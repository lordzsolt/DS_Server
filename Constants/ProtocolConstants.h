#pragma once

#include <string>

extern std::string kServerAddress;
extern unsigned short kServerPort;

extern std::string presharedKey;


enum class MessageType : int32_t {
    Register,
    Log_In,
    Log_In_Response,
    Log_Out,
    Status_Update,
    Private_Message,
    Group_Message,
    Send_File,
    Function_Call
};

enum class MessageTag : int32_t {
    New,
    Acknowledge,
    Corrupt,
    Missing
};

enum class FunctionType : int32_t {
    Add
};


extern std::string kMessageDelimiter;
extern std::string kMessageKeyUsername;
extern std::string kMessageKeyPassword;
extern std::string kMessageKeyRecipientId;
extern std::string kMessageKeyMessage;


extern unsigned int kMaximumMessageLength;

extern unsigned int kMaximumMessageIndex;
