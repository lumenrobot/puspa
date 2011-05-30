/*-*-c++-*-*/

#ifndef GUI_H
#define GUI_H

#include <vector>
#include <CEGUI.h>
#include <RendererModules/Ogre/CEGUIOgreRenderer.h>
#include <OISEvents.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

class Agent;
class Face;

class GUI
{
public:
    GUI(Agent *a, Face *face);
    ~GUI();
    
    bool injectKeyPress(const OIS::KeyEvent& keyEvent);
    bool injectKeyRelease(const OIS::KeyEvent& keyEvent);
    bool injectMouseMove(const OIS::MouseEvent& mouseEvent);
    bool injectMousePress(const OIS::MouseEvent& mouseEvent, OIS::MouseButtonID mouseButtonID);
    bool injectMouseRelease(const OIS::MouseEvent& mouseEvent, OIS::MouseButtonID mouseButtonID);

private:
    bool handleKeyDown(const CEGUI::EventArgs& eventArgs);
    bool handleSubmit(const CEGUI::EventArgs& eventArgs);
    
    Agent *agent;
    
    CEGUI::OgreRenderer *ogreRenderer;
    CEGUI::Window *guiConsole;
    static const unsigned int EntryBoxID;
    int historyPosition;
    std::vector<CEGUI::String> history;
};

#endif
