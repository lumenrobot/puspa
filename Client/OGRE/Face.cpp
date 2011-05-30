#include <iostream>
#include <OgreConfigFile.h>
#include <OgreException.h>
#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include <OgreViewport.h>
#include <OgreAnimationState.h>
#include <OgreMeshManager.h>
#include <OgreAnimation.h>
#include <OgreEntity.h>
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#include <OSX/macUtils.h>
#endif
#include "GUI.h"
#include "Face.h"

using namespace Ogre;
using namespace OIS;

Face::Face() :
gui(NULL),
log(0),
root(0),
renderWindow(0),
inputManager(0),
keyboard(0),
mouse(0),
toBeShutDown(false)
{
#pragma mark Log Manager
    OGRE_NEW LogManager();
    log = LogManager::getSingleton().createLog("Ogre.log", true);
    log->setDebugOutputEnabled(true);
	
#pragma mark Plug-Ins
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#ifdef _DEBUG
    root = OGRE_NEW Root("plugins_d.cfg");
#else
    root = OGRE_NEW Root();
#endif
#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
    root = OGRE_NEW Root(macBundlePath() + "/Contents/Resources/plugins.cfg");
#else
    root = OGRE_NEW Root("/usr/local/share/PUSPA/plugins-unix.cfg");
#endif
    
#pragma mark OGRE Resources
    Ogre::String sectionName, typeName, archiveName;
    ConfigFile configurationFile;
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    configurationFile.load("resources.cfg");
#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
    configurationFile.load(macBundlePath() + "/Contents/Resources/resources.cfg");
#else
    configurationFile.load("/usr/local/share/PUSPA/resources.cfg");
#endif
    ConfigFile::SectionIterator sectionIterator = configurationFile.getSectionIterator();
    while (sectionIterator.hasMoreElements()) {
        sectionName = sectionIterator.peekNextKey();
        ConfigFile::SettingsMultiMap *settings = sectionIterator.getNext();
        ConfigFile::SettingsMultiMap::iterator iterator;
        for (iterator = settings->begin(); iterator != settings->end(); ++iterator) {
            typeName = iterator->first;
            archiveName = iterator->second;
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
            if (!StringUtil::startsWith(archiveName, "/", false)) // only adjust relative dirs
                archiveName = Ogre::String(macBundlePath() + "/" + archiveName);
#endif
            ResourceGroupManager::getSingleton().addResourceLocation(archiveName, typeName, sectionName);
        }
    }

#pragma mark Render System
    Ogre::RenderSystem *renderSystem = root->getRenderSystemByName("OpenGL Rendering Subsystem");
    root->setRenderSystem(renderSystem);
    renderSystem->setConfigOption("Full Screen", "No");
    renderSystem->setConfigOption("Video Mode", "800 x 600 @ 32-bit colour");
    
#pragma mark Render Window
    renderWindow = root->initialise(true, "PUSPA");

#pragma mark Resources Initialisation
    TextureManager::getSingleton().setDefaultNumMipmaps(5);
    ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

#pragma mark Scene Manager
    SceneManager *sceneManager;
    try {
        sceneManager = root->createSceneManager(ST_GENERIC, "PUSPA");
    }
    catch (Ogre::Exception& exception) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
        MessageBox(NULL, exception.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        std::cerr << "An exception has occured: " << exception.getFullDescription().c_str() << std::endl;
#endif
    }
    
#pragma mark Camera
    Camera *camera = sceneManager->createCamera("Camera");
    camera->setPosition(0.0f, 0.0f, 80.0f);
    camera->lookAt(0.0f, 0.0f, -1.0f);
    camera->setNearClipDistance(5.0f);

#pragma mark Viewport
    Viewport *viewport = renderWindow->addViewport(camera);
    viewport->setBackgroundColour(ColourValue(0.0f, 0.0f, 0.0f));
    camera->setAspectRatio(Real(viewport->getActualWidth()) / Real(viewport->getActualHeight()));
    viewport->setCamera(camera);

#pragma mark Scene
    // setup some basic lighting for our scene
    sceneManager->setAmbientLight(ColourValue(0.5f, 0.5f, 0.5f));
    sceneManager->createLight()->setPosition(40.0f, 60.0f, 50.0f);
    sceneManager->createLight()->setPosition(-120.0f, -80.0f, -50.0f);
    // pre-load the mesh so that we can tweak it with a manual animation
    MeshPtr headMesh = MeshManager::getSingleton().load("facial.mesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    // create a manual animation, create a pose track for it, and create a keyframe in that track
    VertexPoseKeyFrame *manualKeyFrame = headMesh->createAnimation("Manual", 0.0f)->createVertexTrack(4, VAT_POSE)->createVertexPoseKeyFrame(0.0f);
    // create pose references for the first 15 poses
    for (unsigned int i = 0; i < 15; i++)
        manualKeyFrame->addPoseReference(i, 0.0f);
    // create a head entity from the mesh and attach it to a node with a vertical offset to center it
    Entity *head = sceneManager->createEntity("Head", "facial.mesh");
    sceneManager->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0.0f, -30.0f, 0.0f))->attachObject(head);
    // get the animation states
    //    AnimationState *speakAnimationState = head->getAnimationState("Speak");
    //    AnimationState *manualAnimationState = head->getAnimationState("Manual");
    //    playAnimation = true; // by default, the speaking animation is enabled

#pragma mark Frame Listener
    log->logMessage("*** Initialising OIS ***");
    unsigned long handleWindow = 0;
    ParamList parameterList;
    renderWindow->getCustomAttribute("WINDOW", &handleWindow);
    parameterList.insert(ParamList::value_type("WINDOW", StringConverter::toString(handleWindow)));
    inputManager = InputManager::createInputSystem(parameterList);
    keyboard = static_cast<Keyboard *> (inputManager->createInputObject(OISKeyboard, true));
    mouse = static_cast<Mouse *> (inputManager->createInputObject(OISMouse, true));
    //Set initial mouse clipping size
    windowResized(renderWindow);
    //Register as a Window listener
    WindowEventUtilities::addWindowEventListener(renderWindow, this);
    root->addFrameListener(this);
    keyboard->setEventCallback(this);
    mouse->setEventCallback(this);
    
#pragma mark Initialisation final touch
    //	renderWindow->setActive(true);
    log->logMessage("Initialised!");
}

Face::~Face()
{
    //Remove ourself as a Window listener
    WindowEventUtilities::removeWindowEventListener(renderWindow, this);
    windowClosed(renderWindow);

    if (inputManager)
        InputManager::destroyInputSystem(inputManager);
    
    OGRE_DELETE root;
	OGRE_DELETE log;
}

bool Face::renderOneFrame()
{
    WindowEventUtilities::messagePump();
    
    if (renderWindow->isClosed())
        return false;
    
    // Render a frame
    if (!root->renderOneFrame())
        return false;
    
    return true;
}

bool Face::frameRenderingQueued(const FrameEvent& frameEvent)
{
    if (renderWindow->isClosed())
        return false;
    
    if (toBeShutDown)
        return false;
    
    keyboard->capture();
    mouse->capture();
    
    return true;
}

bool Face::keyPressed(const KeyEvent& keyEvent)
{
    switch (keyEvent.key) {
    case KC_ESCAPE: 
        toBeShutDown = true;
        break;
    default:
        break;
    }

    if (gui)
        gui->injectKeyPress(keyEvent);
    
    return true;
}

bool Face::keyReleased(const KeyEvent& keyEvent)
{
    if (gui)
        gui->injectKeyRelease(keyEvent);
    
    return true;
}

bool Face::mouseMoved(const MouseEvent& mouseEvent)
{
    if (gui)
        gui->injectMouseMove(mouseEvent);

    return true;
}

bool Face::mousePressed(const MouseEvent& mouseEvent, MouseButtonID mouseButtonID)
{
    if (gui)
        gui->injectMousePress(mouseEvent, mouseButtonID);
    
    return true;
}

bool Face::mouseReleased(const MouseEvent& mouseEvent, MouseButtonID mouseButtonID)
{
    if (gui)
        gui->injectMouseRelease(mouseEvent, mouseButtonID);

    return true;
}
