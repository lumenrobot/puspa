/*-*-c++-*-*/

#ifndef AGENT_H
#define AGENT_H

#include <pthread.h>
#include "SocketConfig.h"
#include "GraphicsConfig.h"

#ifdef __cplusplus

#ifdef GRAPHICS_ENGINE_OGRE
class Face;
class GUI;
#endif
#ifdef SERVER_ENGINE_AIML
class ClientSocket;
#endif

class Agent
{
public:
    Agent();
    ~Agent();

    bool loop();
    void handleText(const char *text);

private:
#ifdef GRAPHICS_ENGINE_OGRE
    Face *face;
    GUI *gui;
#endif

    pthread_t hearThread;
#ifdef SERVER_ENGINE_AIML
    ClientSocket *socket;
#endif

};

#else

typedef struct Agent Agent;

#endif

#ifdef __cplusplus
extern "C" {
#endif
    Agent* handleText(const char *text, Agent *agent);
#ifdef __cplusplus
}
#endif

#endif
