#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#ifdef __FreeBSD__
#include <netinet/in.h>
#endif
#endif
#include <sys/types.h>
#include <iostream>
#include <cerrno>
#include <cstring>
#include "Errors.h"
#include "ClientSocket.h"

void* getInternetAddress(struct sockaddr *socketAddress)
{
    if (socketAddress->sa_family == AF_INET)
        return &(((struct sockaddr_in *)socketAddress)->sin_addr);
    else
        return &(((struct sockaddr_in6 *)socketAddress)->sin6_addr);
}

ClientSocket::ClientSocket()
{
#ifdef _WIN32
    static const char *serverAddress = "puspa.rumahtenda.web.id";
#endif
    static const char *serverPort = "12110";
    
#ifdef _WIN32
	WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
        throw Error("WSAStartup failed.");
#endif

    struct addrinfo addressInfoHint;
    memset(&addressInfoHint, 0, sizeof(addressInfoHint));
    addressInfoHint.ai_family = AF_UNSPEC;
    addressInfoHint.ai_socktype = SOCK_STREAM;
#ifndef _WIN32
    addressInfoHint.ai_flags = AI_PASSIVE;
#endif
    
    int status;
    struct addrinfo *firstInfo;
#ifndef _WIN32
    if ((status = getaddrinfo(NULL, serverPort, &addressInfoHint, &firstInfo)) != 0)
#else
    if ((status = getaddrinfo(serverAddress, serverPort, &addressInfoHint, &firstInfo)) != 0)
#endif
        throw GetAddressInfoError(status);
    
    struct addrinfo *infoListPointer;
    for (infoListPointer = firstInfo; infoListPointer != NULL; infoListPointer = infoListPointer->ai_next) {
        errno = 0;
        if ((socketFD = socket(firstInfo->ai_family, firstInfo->ai_socktype, firstInfo->ai_protocol)) == -1) {
            throw Error(errno);
            continue;
        }
        errno = 0;
        if (connect(socketFD, firstInfo->ai_addr, firstInfo->ai_addrlen) == -1) {
            throw Error(errno);
            continue;
        }
        break;
    }
    if (infoListPointer == NULL)
        throw Error("Failed to connect to server.");
    
    char buffer[INET6_ADDRSTRLEN];
    inet_ntop(infoListPointer->ai_family, getInternetAddress((struct sockaddr *)infoListPointer->ai_addr), buffer, sizeof(buffer));
    serverInternetAddress = const_cast<const char*> (buffer);
    
    freeaddrinfo(firstInfo);
}

ClientSocket::~ClientSocket()
{
    errno = 0;
#ifdef _WIN32
	if (closesocket(socketFD) != 0)
#else
    if (close(socketFD) == -1)
#endif
        std::cerr << strerror(errno);

#ifdef _WIN32
	WSACleanup();
#endif
}

const char* ClientSocket::receive()
{
    int numOfBytes;
    errno = 0;
    if ((numOfBytes = recv(socketFD, inputBuffer, INPUT_BUFFER_SIZE, 0)) == -1)
        throw Error(errno);
    inputBuffer[numOfBytes] = '\0';
    
    return inputBuffer;
}

void ClientSocket::send(const char *outputString) const
{
    errno = 0;
    if (::send(socketFD, outputString, strlen(outputString), 0) == -1)
        throw Error(errno);
}
