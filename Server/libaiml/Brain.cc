#include <cstdlib>
#include <iostream>
#include <std_utils/std_util.h>
#include "Errors.h"
#include "Brain.h"

using namespace std;
using namespace aiml;

Brain::Brain()
{
    cerr << "Loading AIML Interpreter...\n";
    interpreter = cInterpreter::newInterpreter();
    cerr << "AIML Interpreter is ready.\n";
	initialiseInterpreter();
}

Brain::~Brain()
{
    cInterpreter::freeInterpreter(interpreter);
}

void Brain::onAimlLoad(const string& fileName)
{
    cerr << "Loaded " << fileName << ".\n";
}

void Brain::initialiseInterpreter()
{
    interpreter->registerCallbacks(this);
    
    cerr << "Initialising Interpreter...\n";
    if (!interpreter->initialize("/usr/local/share/PUSPA/libaiml.xml"))
        throwException();
}

void Brain::throwException()
{
    ostringstream errorStringStream;
    errorStringStream << "ERROR: " << interpreter->getErrorStr(interpreter->getError()) << " (" << interpreter->getError() << ")";
    if (interpreter->getRuntimeErrorStr().empty())
        throw Error(errorStringStream.str());
    else
        throw Error(errorStringStream.str() + "Runtime Error: " + interpreter->getRuntimeErrorStr());
}

bool Brain::process(const string& input)
{
    if (std_util::strip(input).empty())
        return false;
    
    if (!interpreter->respond(input, string(getenv("USER")), response))
        throwException();
    
    return true;
}

string& Brain::getResponse()
{
    return response;
}
