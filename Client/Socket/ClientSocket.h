/*-*-c++-*-*/

#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#define INPUT_BUFFER_SIZE 1024

class ClientSocket
{
public:
    ClientSocket();
    ~ClientSocket();
    inline const char* getServerInternetAddress() { return serverInternetAddress; }
    const char* receive();
    void send(const char *outputString) const;
private:
    int socketFD;
    char inputBuffer[INPUT_BUFFER_SIZE + 1];
    const char* serverInternetAddress;
};

#endif
