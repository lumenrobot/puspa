/*-*-c++-*-*/

#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include <string>

class ServerSocket
{
public:
    ServerSocket();
    ~ServerSocket();
    void listen() const;
    void accept();
    void receive(std::string& inputString) const;
    void send(const char *outputString) const;
private:
    int connectionSocketFD;
    int communicationSocketFD;
};

#endif
