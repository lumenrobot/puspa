#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <libaiml/aiml.h>

class Brain : public aiml::cInterpreterCallbacks
{
public:
    Brain();
    ~Brain();
    void onAimlLoad(const std::string& fileName);
    void initialiseInterpreter();
    void throwException();
    bool process(const std::string& input);
    std::string& getResponse();
private:
    aiml::cInterpreter *interpreter;
    std::string response;
};

#endif
