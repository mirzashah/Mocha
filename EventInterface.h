/*****************************************************************************/
// Filename: EventInterface.h
/*****************************************************************************/
// Description: This class defines an interface used by applications using Mocha
// to give the Mocha engine awareness of events generated by the user's application
// toolkit of choice (e.g. Qt, MFC, Gtk, wxWidgets).
// Mocha is application toolkit independent, so it can be used with any toolkit
// that can create an OpenGL context. However, some glue must be written, and
// this is part of that glue.
/*****************************************************************************/

#ifndef EVENT_INTERFACE_H_DEFINED
#define EVENT_INTERFACE_H_DEFINED

#include <MochaObject.h>

namespace Mocha
{

class CSceneManager;
class CEventInterface : public CMochaObject
{
    public:
        CEventInterface(CSceneManager& holder);
        virtual ~CEventInterface();

        //Mouse
        void OnLeftMouseDown(CDevicePoint mousePos);
        void OnLeftMouseDoubleClick(CDevicePoint mousePos);
        void OnLeftMouseUp(CDevicePoint mousePos);
        void OnMouseMove(CDevicePoint mousePos);
        void OnRightMouseDown(CDevicePoint mousePos);
        void OnRightMouseDoubleClick(CDevicePoint mousePos);
        void OnRightMouseUp(CDevicePoint mousePos);

        //Keyboard
        void OnKeyDown(char c);
        void OnKeyUp(char c);

        //View window
        void OnMove(int newX, int newY);
        void OnResize(int newWidth, int newHeight);

        //Other
        /**
        * Invoke this on timer
        */
        void OnUpdate();

        /**
        * Invoke this before invoking rendering
        */
        void OnPrerender();

        /**
        * Invoke this when time to render
        */
        void OnRender();

    private:
        CSceneManager& Holder();

    private:
        CSceneManager& _holder;

};
};

#endif