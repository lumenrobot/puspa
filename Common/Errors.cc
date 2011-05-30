#include <cstring>
#include <cerrno>
#include <sys/types.h>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netdb.h>
#endif
#include "Errors.h"

Error::Error(int errNo)
{
    message = strerror(errNo);
}

Error::Error(const std::string& errorMessage) : message(errorMessage.c_str())
{
}

GetAddressInfoError::GetAddressInfoError(int status)
{
    message = gai_strerror(status);
}
