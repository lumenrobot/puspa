#include <opencog/util/Logger.h>
#include "Brain.h"

using namespace std;
using namespace opencog;

Brain::Brain()
{
    // setup global logger
    logger().setLevel(Logger::DEBUG);
    logger().setPrintToStdoutFlag(config().get_bool("LOG_TO_STDOUT"));

    logger().info("[Brain] constructor");
}

Brain::~Brain()
{
    logger().info("[Brain] destructor");
}

// factory method
BaseServer* Brain::derivedCreateInstance()
{
    ::logger().info("[Brain] createInstance");
    return new Brain();
}

void Brain::serverLoop(void)
{
    logger().info("[Brain] serverLoop");
    CogServer::serverLoop();
}

bool Brain::process(const string& input)
{
    return true;
}

string& Brain::getResponse()
{
    return response;
}
