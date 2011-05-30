#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif
#include "Agent.h"

#ifdef __cplusplus
extern "C" {
#endif
    
#ifdef _WIN32
    INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR strCmdLine, INT iCmdShow)
#else
    int main(int argc, char *argv[])
#endif
    {
        Agent agent;
        while (agent.loop())
            ;

        return 0;
    }
    
#ifdef __cplusplus
}
#endif
