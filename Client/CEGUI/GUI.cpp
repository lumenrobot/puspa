#include <OgreRoot.h>
#include <OgreHardwarePixelBuffer.h>
#include "Agent.h"
#include "Face.h"
#include "GUI.h"

using namespace CEGUI;
using namespace Ogre;
using namespace OIS;

const unsigned int GUI::EntryBoxID = 1;

GUI::GUI(Agent *a, Face *face) : agent(a)
{
#pragma mark CEGUI Resources
    ogreRenderer = &OgreRenderer::bootstrapSystem();
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    Imageset::setDefaultResourceGroup("Win32");
    CEGUI::Font::setDefaultResourceGroup("Win32");
    Scheme::setDefaultResourceGroup("Win32");
    WidgetLookManager::setDefaultResourceGroup("Win32");
    WindowManager::setDefaultResourceGroup("Win32");
#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
    Imageset::setDefaultResourceGroup("Apple");
    CEGUI::Font::setDefaultResourceGroup("Apple");
    Scheme::setDefaultResourceGroup("Apple");
    WidgetLookManager::setDefaultResourceGroup("Apple");
    WindowManager::setDefaultResourceGroup("Apple");
#else
    Imageset::setDefaultResourceGroup("Unix");
    CEGUI::Font::setDefaultResourceGroup("Unix");
    Scheme::setDefaultResourceGroup("Unix");
    WidgetLookManager::setDefaultResourceGroup("Unix");
    WindowManager::setDefaultResourceGroup("Unix");
#endif
    
#pragma mark GUI
    SchemeManager::getSingleton().create("TaharezLook.scheme");
    System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseArrow");
    WindowManager& windowManager = WindowManager::getSingleton();
    Window *sheet = windowManager.createWindow("DefaultWindow", "CEGUIDemo/Sheet");
    System::getSingleton().setGUISheet(sheet);
    
    Root& root = Root::getSingleton();
    TexturePtr texturePointer = root.getTextureManager()->createManual("RTT",
                                                                       ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
                                                                       TEX_TYPE_2D,
                                                                       512,
                                                                       512,
                                                                       0,
                                                                       PF_R8G8B8,
                                                                       TU_RENDERTARGET);
    RenderTexture *renderTexture = texturePointer->getBuffer()->getRenderTarget();
    Camera *guiCamera = root.getSceneManager("PUSPA")->createCamera("RTTCam");
    guiCamera->setPosition(100.0f, -100.0f, -400.0f);
    guiCamera->lookAt(0.0f, 0.0f, -300.0f);
    Viewport *guiViewport = renderTexture->addViewport(guiCamera);
    guiViewport->setOverlaysEnabled(false);
    guiViewport->setClearEveryFrame(true);
    guiViewport->setBackgroundColour(ColourValue::Black);
    
    CEGUI::Texture& guiTexture = ogreRenderer->createTexture(texturePointer);
    Imageset& imageSet = ImagesetManager::getSingleton().create("RTTImageset", guiTexture);
    imageSet.defineImage("RTTImage",
                         CEGUI::Point(0.0f, 0.0f),
                         CEGUI::Size(guiTexture.getSize().d_width,
                                     guiTexture.getSize().d_height),
                         CEGUI::Point(0.0f, 0.0f));
    Window *staticImage = WindowManager::getSingleton().createWindow("TaharezLook/StaticImage");
    staticImage->setSize(UVector2(UDim(1.0f, 0.0f), UDim(0.1f, 0.0f)));
    staticImage->setPosition(UVector2(UDim(0.0f, 0.0f), UDim(0.9f, 0.0f)));
    staticImage->setProperty("Image", PropertyHelper::imageToString(&imageSet.getImage("RTTImage")));
    sheet->addChildWindow(staticImage);
    guiConsole = windowManager.loadWindowLayout("Console.layout");
    guiConsole->subscribeEvent(Window::EventKeyDown, Event::Subscriber(&GUI::handleKeyDown, this));
    guiConsole->getChild(EntryBoxID)->subscribeEvent(Editbox::EventTextAccepted, Event::Subscriber(&GUI::handleSubmit, this));
    staticImage->addChildWindow(guiConsole);
    
    face->gui = this;
}

GUI::~GUI()
{
}

bool GUI::injectKeyPress(const KeyEvent& keyEvent)
{
    System& system = System::getSingleton();
    system.injectKeyDown(keyEvent.key);
    system.injectChar(keyEvent.text);
    
    return true;
}

bool GUI::injectKeyRelease(const KeyEvent& keyEvent)
{
    System::getSingleton().injectKeyUp(keyEvent.key);
    
    return true;
}

static MouseButton convertButton(MouseButtonID mouseButtonID)
{
    switch (mouseButtonID) {
        case MB_Left:
            return LeftButton;
            
        case MB_Right:
            return RightButton;
            
        case MB_Middle:
            return MiddleButton;
            
        default:
            return LeftButton;
    }
}

bool GUI::injectMouseMove(const MouseEvent& mouseEvent)
{
    System& system = System::getSingleton();
    system.injectMouseMove(mouseEvent.state.X.rel, mouseEvent.state.Y.rel);
    // Scroll wheel.
    if (mouseEvent.state.Z.rel)
        system.injectMouseWheelChange(mouseEvent.state.Z.rel / 120.0f);
    
    return true;
}

bool GUI::injectMousePress(const MouseEvent& mouseEvent, MouseButtonID mouseButtonID)
{
    System::getSingleton().injectMouseButtonDown(convertButton(mouseButtonID));
    
    return true;
}

bool GUI::injectMouseRelease(const MouseEvent& mouseEvent, MouseButtonID mouseButtonID)
{
    System::getSingleton().injectMouseButtonUp(convertButton(mouseButtonID));
    
    return true;
}

bool GUI::handleKeyDown(const EventArgs& eventArgs)
{
    // get the text entry editbox
    Editbox *editbox = static_cast<Editbox *> (guiConsole->getChild(EntryBoxID));
    
    switch (static_cast<const KeyEventArgs&> (eventArgs).scancode) {
        case Key::ArrowUp:
            historyPosition = ceguimax(historyPosition - 1, -1);
            if (historyPosition >= 0) {
                editbox->setText(history[historyPosition]);
                editbox->setCaratIndex(static_cast<size_t> (-1));
            } else
                editbox->setText("");
            
            editbox->activate();
            break;
            
        case Key::ArrowDown:
            historyPosition = ceguimin(historyPosition + 1, static_cast<int> (history.size()));
            if (historyPosition < static_cast<int> (history.size())) {
                editbox->setText(history[historyPosition]);
                editbox->setCaratIndex(static_cast<size_t> (-1));
            } else
                editbox->setText("");
            
            editbox->activate();
            break;
            
        default:
            return false;
	}
    
    return true;
}

bool GUI::handleSubmit(const EventArgs& eventArgs)
{
    // get the text entry editbox
    Editbox *editbox = static_cast<Editbox *> (guiConsole->getChild(EntryBoxID));
    // get text out of the editbox
    CEGUI::String edit_text(editbox->getText());
    // if the string is not empty
    if (!edit_text.empty()) {
        // add this entry to the command history buffer
        history.push_back(edit_text);
        // reset history position
        historyPosition = history.size();
        // this is the member function that the agent uses to send the text to the brain
        agent->handleText(editbox->getText().c_str());
        // erase text in text entry box.
        editbox->setText("");
    }
    
    // re-activate the text entry box
    editbox->activate();
    
    return true;
}
