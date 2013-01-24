#include <EventInterface.h>
#include <SceneManager.h>
#include <EventVisitor.h>

namespace Mocha
{

/**********************************************/
CEventInterface::CEventInterface(CSceneManager& holder) :
_holder(holder)
/**********************************************/
{
}

/**********************************************/
CEventInterface::~CEventInterface()
/**********************************************/
{
}

/**********************************************/
CSceneManager& CEventInterface::Holder()
/**********************************************/
{
    return(_holder);
}

/**********************************************/
void CEventInterface::OnLeftMouseDown(CDevicePoint mousePos)
/**********************************************/
{
    Holder().OnLeftMouseDown(mousePos);
}

/**********************************************/
void CEventInterface::OnLeftMouseDoubleClick(CDevicePoint mousePos)
/**********************************************/
{
    Holder().OnLeftMouseDoubleClick(mousePos);
}

/**********************************************/
void CEventInterface::OnLeftMouseUp(CDevicePoint mousePos)
/**********************************************/
{
    Holder().OnLeftMouseUp(mousePos);
}

/**********************************************/
void CEventInterface::OnMouseMove(CDevicePoint mousePos)
/**********************************************/
{
    Holder().OnMouseMove(mousePos);
}

/**********************************************/
void CEventInterface::OnRightMouseDown(CDevicePoint mousePos)
/**********************************************/
{
    Holder().OnRightMouseDown(mousePos);
}

/**********************************************/
void CEventInterface::OnRightMouseDoubleClick(CDevicePoint mousePos)
/**********************************************/
{
    Holder().OnRightMouseDoubleClick(mousePos);
}

/**********************************************/
void CEventInterface::OnRightMouseUp(CDevicePoint mousePos)
/**********************************************/
{
    Holder().OnRightMouseUp(mousePos);
}

/**********************************************/
void CEventInterface::OnKeyDown(char c)
/**********************************************/
{
    Holder().OnKeyDown(c);
}

/**********************************************/
void CEventInterface::OnKeyUp(char c)
/**********************************************/
{
    Holder().OnKeyUp(c);
}

/**********************************************/
void CEventInterface::OnMove(int newX, int newY)
/**********************************************/
{
    Holder().OnMove(newX, newY);
}

/**********************************************/
void CEventInterface::OnPrerender()
/**********************************************/
{
    Holder().OnPrerender();
}

/**********************************************/
void CEventInterface::OnRender()
/**********************************************/
{
    Holder().OnRender();
}

/**********************************************/
void CEventInterface::OnResize(int newWidth, int newHeight)
/**********************************************/
{
    Holder().OnResize(newWidth, newHeight);
}

/**********************************************/
void CEventInterface::OnUpdate()
/**********************************************/
{
    Holder().OnUpdate();
}

};
