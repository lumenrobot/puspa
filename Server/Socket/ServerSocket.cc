#include <iostream>
#include <cerrno>
#include <cstring>
#include <signal.h>
#include <sys/types.h>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#ifdef __FreeBSD__
#include <netinet/in.h>
#endif
#endif
#include "Errors.h"
#include "ServerSocket.h"

using namespace std;

void signalChildHandler(int)
{
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
}

void* getInternetAddress(struct sockaddr *socketAddress)
{
    if (socketAddress->sa_family == AF_INET)
        return &(((struct sockaddr_in *)socketAddress)->sin_addr);
    else
        return &(((struct sockaddr_in6 *)socketAddress)->sin6_addr);
}

ServerSocket::ServerSocket()
{
    static const string port = "12110";
    
#ifdef _WIN32
	WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
        throw Error("WSAStartup failed.");
#endif

    struct addrinfo addressInfoHint;
    memset(&addressInfoHint, 0, sizeof(addressInfoHint));
    addressInfoHint.ai_family = AF_UNSPEC;
    addressInfoHint.ai_socktype = SOCK_STREAM;
    addressInfoHint.ai_flags = AI_PASSIVE;
    
    int connectionStatus;
    struct addrinfo *firstInfo;
    if ((connectionStatus = getaddrinfo(NULL, port.c_str(), &addressInfoHint, &firstInfo)) != 0)
        throw GetAddressInfoError(connectionStatus);
    
    struct addrinfo *infoListPointer;
    for (infoListPointer = firstInfo; infoListPointer != NULL; infoListPointer = infoListPointer->ai_next) {
        errno = 0;
        if ((connectionSocketFD = socket(firstInfo->ai_family, firstInfo->ai_socktype, firstInfo->ai_protocol)) == -1) {
            throw Error(errno);
            continue;
        }
        int optVal = 1;
        errno = 0;
        if (setsockopt(connectionSocketFD, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(optVal)) == -1)
            throw Error(errno);
        if (bind(connectionSocketFD, firstInfo->ai_addr, firstInfo->ai_addrlen) == -1) {
            errno = 0;
            if (close(connectionSocketFD) == -1)
                throw Error(errno);
            errno = 0;
            throw Error(errno);
            continue;
        }
        break;
    }
    if (infoListPointer == NULL)
        throw Error("Failed to bind to port " + port + ".");
    
    freeaddrinfo(firstInfo);
}

ServerSocket::~ServerSocket()
{
    errno = 0;
#ifdef _WIN32
	if (closesocket(connectionSocketFD) != 0)
#else
    if (close(connectionSocketFD) == -1)
#endif
	    cerr << strerror(errno);

#ifdef _WIN32
    WSACleanup();
#endif
}

void ServerSocket::listen() const
{
    static const int backLog = 2;
    errno = 0;
    if (::listen(connectionSocketFD, backLog) == -1)
        throw Error(errno);
    
    struct sigaction signalAction;
    signalAction.sa_handler = signalChildHandler;
    sigemptyset(&signalAction.sa_mask);
    signalAction.sa_flags = SA_RESTART;
    errno = 0;
    if (sigaction(SIGCHLD, &signalAction, NULL) == -1)
        throw Error(errno);
}

void ServerSocket::accept()
{
    struct sockaddr_storage clientAddress;
    socklen_t addressSize = sizeof(clientAddress);
    errno = 0;
    if ((communicationSocketFD = ::accept(connectionSocketFD, (struct sockaddr *)&clientAddress, &addressSize)) == -1)
        throw Error(errno);
    
    char buffer[INET6_ADDRSTRLEN];
    inet_ntop(clientAddress.ss_family, getInternetAddress((struct sockaddr *)&clientAddress), buffer, sizeof(buffer));
	cerr << "Got a connection from " << buffer << endl;
}

void ServerSocket::receive(string& inputString) const
{
    inputString = "";
    
    const int inputBufferSize = 100;
    char inputBuffer[inputBufferSize + 1];
    memset(inputBuffer, 0, inputBufferSize + 1);
    
    int status = recv(communicationSocketFD, inputBuffer, inputBufferSize, 0);
    errno = 0;
    if (status == -1)
        throw Error(errno);
    else if (status == 0) {
        errno = 0;
        if (close(communicationSocketFD) == -1)
            throw Error(errno);
    }
    
    inputString = inputBuffer;
}

void ServerSocket::send(const char *outputString) const
{
    errno = 0;
    if (::send(communicationSocketFD, outputString, strlen(outputString), 0) == -1)
        throw Error(errno);
}
