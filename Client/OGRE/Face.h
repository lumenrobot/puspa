/*-*-c++-*-*/

#ifndef FACE_H
#define FACE_H

#include <OgreWindowEventUtilities.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreRenderWindow.h>
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

class GUI;

class Face : public Ogre::WindowEventListener, Ogre::FrameListener, OIS::KeyListener, OIS::MouseListener
{
public:
    Face();
    ~Face();
    
    GUI *gui;
    bool renderOneFrame();

private:
    // Ogre::FrameListener
    bool frameRenderingQueued(const Ogre::FrameEvent& frameEvent);
    // OIS::KeyListener
    bool keyPressed(const OIS::KeyEvent& keyEvent);
    bool keyReleased(const OIS::KeyEvent& keyEvent);
    // OIS::MouseListener
    bool mouseMoved(const OIS::MouseEvent& mouseEvent);
    bool mousePressed(const OIS::MouseEvent& mouseEvent, OIS::MouseButtonID mouseButtonID);
    bool mouseReleased(const OIS::MouseEvent& mouseEvent, OIS::MouseButtonID mouseButtonID);

	Ogre::Log *log;
    Ogre::Root *root;
    Ogre::RenderWindow *renderWindow;

    OIS::InputManager *inputManager;
    OIS::Keyboard *keyboard;
    OIS::Mouse *mouse;
    bool toBeShutDown;
};

#endif
