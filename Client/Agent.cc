#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <direct.h>
#elif __APPLE__
#include <unistd.h>
#endif
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <pthread.h>

#ifdef GRAPHICS_ENGINE_OGRE
#include "Face.h"
#include "GUI.h"
#endif
#include "Mouth.h"
#include "Ear.h"
#include "Agent.h"

#ifdef SERVER_ENGINE_OPENCOG
#include "whirr-sockets.h"
#elif defined(SERVER_ENGINE_AIML)
#include "Errors.h"
#include "ClientSocket.h"
#endif

using namespace std;

Agent::Agent()
{
#ifdef SERVER_ENGINE_OPENCOG
    whirr_sock_setup();
#elif defined(SERVER_ENGINE_AIML)
    try {
        socket = new ClientSocket();
        cerr << "Connecting to " << socket->getServerInternetAddress() << ".\n";
    }
    catch (Error& error) {
        cerr << error.message << endl;
    }
    catch (GetAddressInfoError& getAddressInfoError) {
        cerr << getAddressInfoError.message << endl;
    }
#endif

#ifdef GRAPHICS_ENGINE_OGRE
    face = new Face();
#ifndef _WIN32
    gui = new GUI(this, face);
#endif
#endif

    pthread_create(&hearThread, NULL, hear_thread, (void *)this);
}

Agent::~Agent()
{
    pthread_cancel(hearThread);

#ifdef GRAPHICS_ENGINE_OGRE
#ifndef _WIN32
    delete gui;
#endif
    delete face;
#endif

#ifdef SERVER_ENGINE_AIML
    delete socket;
#endif
}

bool Agent::loop()
{
#ifdef GRAPHICS_ENGINE_OGRE
    return face->renderOneFrame();
#else
    return true;
#endif
}

#ifdef SERVER_ENGINE_OPENCOG
/* return true if not all whitespace */
static bool is_nonblank(const char * str)
{
	size_t len = strlen(str);
	if (0 == len) return false;
	size_t blanks = strspn(str, " \n\r\t\v");
	if (blanks == len) return false;
	return true;
}
#endif

void Agent::handleText(const char *text)
{
    pthread_t speakThread;

#ifdef SERVER_ENGINE_OPENCOG

    const char *nick;

	#ifdef _WIN32
        nick = getenv("USERNAME");
	#else
        nick = getenv("USER");
	#endif

	size_t textlen = strlen(text);
	size_t len = textlen;
	len += strlen ("(say-id-english )");
	len += strlen (nick);
	len += 120;

	char * cmdline = (char *) malloc(sizeof (char) * (len+1));

    // Get into the opencog scheme shell, and run the command
    strcpy (cmdline, "scm hush\n(say-id-english \"");
    strcat (cmdline, nick);
    strcat (cmdline, "\" \"");
    size_t toff = strlen(cmdline);
    strcat (cmdline, text);
    strcat (cmdline, "\")\n");

    // strip out quotation marks, replace with blanks, for now.
    for (size_t i =0; i<textlen; i++)
    {
        if ('\"' == cmdline[toff+i]) cmdline[toff+i] = ' ';
    }

#define FLOOD_CHAR_COUNT 120

	size_t flood_cnt = FLOOD_CHAR_COUNT;
	size_t cnt = 0;
	bool dosend = true;

	// printf ("Sending to opencog: %s\n", cmdline);
	char * reply = whirr_sock_io (cmdline);
	free(cmdline);
	cmdline = NULL;

	printf ("opencog reply: %s\n", reply);

	/* Each newline has to be on its own line */
	/* Limit length of reply so we don't get kicked for flooding */
	char * p = reply;
	while (*p)
	{
		char *ep = strchr (p, '\n');

		// The last line -- no newline found.
		if (!ep)
		{
			if (is_nonblank(p)) {
		#ifndef _WIN32
                char *pcopy = (char *) malloc(sizeof (char) * (strlen(p)+1));
                strcpy(pcopy, p);
                pthread_create(&speakThread, NULL, speak_thread, (void *) pcopy);
		#endif
            }
			break;
		}
		ep ++;
		int save = *ep;
		*ep = 0x0;

		// If the line starts with ":scm", resubmit it to the
		// server. This is a kind-of cheap, hacky way of doing
		// multi-processing.
		if (0 == strncmp(p, ":scm", 4))
		{
			char * cr = strchr(p, '\r');
			if (cr) *cr = '\n';
			char * r = whirr_sock_io (p+1);
			free(reply);
			reply = r;
			p = reply;
			printf ("opencog reply: %s\n", reply);
			continue;
		}

		// If the line starts with ":dbg", the do not send to chatroom
		if (0 == strncmp(p, ":dbg", 4))
		{
			*ep = save;
			p = ep;
			dosend = false;
			continue;
		}
		if (0 == strncmp(p, ":end-dbg", 8))
		{
			*ep = save;
			p = ep;
			dosend = true;
			continue;
		}

		// Else send output to chatroom
		if (dosend && is_nonblank(p))
		{
	    #ifndef _WIN32
            char *pcopy = (char *) malloc(sizeof (char) * (strlen(p)+1));
            strcpy(pcopy, p);
            pthread_create(&speakThread, NULL, speak_thread, (void *) pcopy);
	    #endif
			cnt += strlen (p);

			/* Sleep so that we don't get kicked for flooding */
			if (flood_cnt < cnt) {
			    #ifdef _WIN32
			    Sleep(1);
			    #else
			    sleep(1);
			    #endif
			    cnt -= FLOOD_CHAR_COUNT;
			}
			if (50 < flood_cnt) flood_cnt -= 15;
		}
		*ep = save;
		p = ep;
	}
	free(reply);

#elif defined(SERVER_ENGINE_AIML)

    try {
        socket->send(text);
    }
    catch (Error& error) {
#ifdef _WIN32
        MessageBox(NULL, error.message, "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        cerr << error.message << endl;
#endif
    }

#ifndef _WIN32
    const char *reply = socket->receive();
    char *replyCopy = (char *) malloc(sizeof (char) * (strlen(reply)+1));
    strcpy(replyCopy, reply);
    pthread_create(&speakThread, NULL, speak_thread, (void *) replyCopy);
#endif

#endif
}

Agent* handleText(const char *text, Agent *agent)
{
    agent->handleText(text);

    return agent;
}
