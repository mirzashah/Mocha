/*****************************************************************************/
// Filename: EventRegister.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef EVENT_REGISTER_H_DEFINED
#define EVENT_REGISTER_H_DEFINED

#include <MochaObject.h>

namespace Mocha
{

class CEventRegister : public CMochaObject
{
    friend class CSceneNode;
    public:
        CEventRegister();
        virtual ~CEventRegister();

        bool           IsRegistered(MochaEventType eventToCatch);
        bool           IsRegisteredForSelection(MochaEventType eventToCatch);
        void           Register(MochaEventType eventToCatch, bool onlyOnSelection);
        void           Unregister(MochaEventType eventToDisable);

    private:
        void           ClearEventMask();
        void           ClearSelectionMask();
        int            EventMask();
        void           EventMask(int mask);
        int            SelectionMask();
        void           SelectionMask(int mask);

    private:
        int           _eventMask;
        int           _SelectionMask;

};

};

#endif
