#include <EventRegister.h>

namespace Mocha
{

/***************************************/
CEventRegister::CEventRegister()
/***************************************/
{
    ClearEventMask();
    ClearSelectionMask();
}

/***************************************/
CEventRegister::~CEventRegister()
/***************************************/
{
}

/***************************************/
void CEventRegister::ClearEventMask()
/***************************************/
{
    EventMask(0);
}

/***************************************/
void CEventRegister::ClearSelectionMask()
/***************************************/
{
    SelectionMask(0);
}

/***************************************/
int CEventRegister::EventMask()
/***************************************/
{
    return(_eventMask);
}

/***************************************/
void CEventRegister::EventMask(int mask)
/***************************************/
{
    _eventMask = mask;
}

/***************************************/
bool CEventRegister::IsRegistered(MochaEventType eventToCatch)
/***************************************/
{
    return(eventToCatch == (EventMask() & eventToCatch));
}

/***************************************/
bool CEventRegister::IsRegisteredForSelection(MochaEventType eventToCatch)
/***************************************/
{
    return(eventToCatch == (SelectionMask() & eventToCatch));
}

/***************************************/
int CEventRegister::SelectionMask()
/***************************************/
{
    return(_SelectionMask);
}

/***************************************/
void CEventRegister::SelectionMask(int mask)
/***************************************/
{
    _SelectionMask = mask;
}

/***************************************/
void CEventRegister::Register(MochaEventType eventToCatch, bool onlyOnSelection)
/***************************************/
{
    EventMask(EventMask() | eventToCatch);
    if(onlyOnSelection)
        SelectionMask(SelectionMask() | eventToCatch);
    else
        SelectionMask(SelectionMask() & ~(eventToCatch));
}

/***************************************/
void CEventRegister::Unregister(MochaEventType eventToDisable)
/***************************************/
{
    EventMask(EventMask() & (~(eventToDisable)));
    SelectionMask(SelectionMask() & (~(eventToDisable)));
}

}
