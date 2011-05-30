/*-*-c++-*-*/

#ifndef ERRORS_H
#define ERRORS_H

#include <string>

struct Error
{
    Error(int errNo);
    Error(const std::string& errorMessage);
    const char* message;
};

struct GetAddressInfoError
{
    GetAddressInfoError(int status);
    const char* message;
};

#endif
