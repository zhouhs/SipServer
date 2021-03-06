#pragma once
#ifndef SIPSERVER_SIPMESSAGE_HPP
#define SIPSERVER_SIPMESSAGE_HPP

#include <map>

#include <asio/ip/udp.hpp>


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
    private:
        std::string startString;
        std::multimap<std::string, std::string> headers;
        std::multimap<std::string, std::string> body;
        SipMessageType type;
        MethodType method = MethodType::NONE;

        std::string senderId;
        asio::ip::udp::endpoint senderEndPoint;

        static SipMessageType parseType(std::string&);
        static MethodType parseMethod(std::string&);
        std::pair<std::string, asio::ip::udp::endpoint> parseContact(std::string& str);

    public:
        SipMessage() = default;
        SipMessage(const char* rowStringMessage);
        SipMessage(std::string startString,
                   std::multimap<std::string, std::string> headers,
                   std::multimap<std::string, std::string> body);
        SipMessageType getSipMessageType();
        MethodType getMethod();
        std::string getSenderId();
        asio::ip::udp::endpoint getSenderEndPoint();
        std::multimap<std::string, std::string> getHeaders();
        std::multimap<std::string, std::string> getBody();

        operator std::string() const;
};


#endif //SIPSERVER_SIPMESSAGE_HPP
