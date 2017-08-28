#pragma once
#ifndef SIPSERVER_SIPMESSAGE_HPP
#define SIPSERVER_SIPMESSAGE_HPP

#include <map>

enum class SipMessageType {
    Request = 0,
    Response = 1,
    Unknown = 2
};

enum class MethodType {
    NONE = 0,
    REGISTER = 1
};

class SipMessage {
    friend class SipParser;

    private:
        std::string startString;
        std::multimap<std::string, std::string> headers;
        std::multimap<std::string, std::string> body;
        SipMessageType type;
        MethodType method = MethodType::NONE;

        static SipMessageType parseType(std::string&);
        static MethodType parseMethod(std::string&);

    public:
        SipMessage() = default;
        SipMessage(const char* rowStringMessage);
        SipMessageType getSipMessageType();
        MethodType getMethod();
        operator std::string() const;
};


#endif //SIPSERVER_SIPMESSAGE_HPP
