/*-*-c++-*-*/

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <opencog/server/CogServer.h>

class Brain : public opencog::CogServer
{
public:
    Brain();
    ~Brain();
    static opencog::BaseServer* derivedCreateInstance(void);
    void serverLoop();
    bool process(const std::string& input);
    std::string& getResponse();
private:
    std::string response;
};

#endif
