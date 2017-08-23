#pragma once
#ifndef SIPSERVER_ERRORCODE_HPP
#define SIPSERVER_ERRORCODE_HPP

enum class ErrorCode {
    SUCCESSFULLY = 0,
    PORT_UNAVAILABLE = 1,
    PORT_SYSTEM = 2,
    NETWORK_INTERFACE_ERROR = 3,
    UNKNOWN = 4
};

#endif //SIPSERVER_ERRORCODE_HPP