#include <SceneNode.h>
#include <SceneManager.h>
#include <ProjectionNode.h>
#include <BoundAreaNode.h>
#include <MapSystemNode.h>

namespace Mocha
{
/**********************************************/
CSceneNode::CSceneNode()
/**********************************************/
{
}

/**********************************************/
CSceneNode::~CSceneNode()
/**********************************************/
{
}

/**********************************************/
bool CSceneNode::AddChild(CSceneNode* child)
/**********************************************/
{
    if(Contains(Children(), child))
        return(false);
    else
    {
        Children(Append(Children(), child));
        return(true);
    }
}

/*****************************************/
double CSceneNode::CartesianExtentBottom()
/*****************************************/
{
    return(CurrentSceneManager()->CartesianExtentBottom());
}

/*****************************************/
double CSceneNode::CartesianExtentLeft()
/*****************************************/
{
    return(CurrentSceneManager()->CartesianExtentLeft());
}

/*****************************************/
double CSceneNode::CartesianExtentRight()
/*****************************************/
{
    return(CurrentSceneManager()->CartesianExtentRight());
}

/*****************************************/
double CSceneNode::CartesianExtentTop()
/*****************************************/
{
    return(CurrentSceneManager()->CartesianExtentTop());
}

/*********************************************/
double CSceneNode::CartesianToDeviceScaleXAxis()
/*********************************************/
{
    return(CurrentSceneManager()->CartesianToDeviceScaleXAxis());
}

/*********************************************/
double CSceneNode::CartesianToDeviceScaleYAxis()
/*********************************************/
{
    return(CurrentSceneManager()->CartesianToDeviceScaleYAxis());
}

/*********************************************/
SceneNodeList CSceneNode::Children()
/*********************************************/
{
    return(_children);
}

/*********************************************/
void CSceneNode::Children(SceneNodeList children)
/*********************************************/
{
    _children = children;
}

/*********************************************/
CDevicePoint CSceneNode::CurrentMousePosition()
/*********************************************/
{
    return(CurrentSceneManager()->CurrentMousePosition());
}

/*********************************************/
CProjectionNode& CSceneNode::CurrentProjection()
/*********************************************/
{
    return(CurrentSceneManager()->CurrentProjection());
}

/*********************************************/
CBoundAreaNode* CSceneNode::CurrentBoundArea()
/*********************************************/
{
    return(CurrentSceneManager()->CurrentBoundArea());
}

/*********************************************/
CMapSystemNode&  CSceneNode::CurrentMapSystem()
/*********************************************/
{
    return(CurrentSceneManager()->CurrentMapSystem());
}

/**********************************************/
CEventRegister& CSceneNode::EventRegister()
/**********************************************/
{
    return(_eventRegister);
}

/*********************************************/
double CSceneNode::GreatCircleDistanceInMeters(const CGeographicalPoint& p1, const CGeographicalPoint& p2)
/*********************************************/
{
    return(CurrentSceneManager()->GreatCircleDistanceInMeters(p1, p2));
}

/*********************************************/
void CSceneNode::InvalidateScene()
/*********************************************/
{
    CurrentSceneManager()->InvalidateScene();
}

/*********************************************/
bool CSceneNode::IsLeftMouseButtonDown()
/*********************************************/
{
    return(CurrentSceneManager()->IsLeftMouseButtonDown());
}

/*********************************************/
bool CSceneNode::IsRightMouseButtonDown()
/*********************************************/
{
    return(CurrentSceneManager()->IsRightMouseButtonDown());
}

/*********************************************/
bool CSceneNode::IsRegistered(MochaEventType eventToCatch)
/*********************************************/
{
    return(EventRegister().IsRegistered(eventToCatch));
}

/*********************************************/
bool CSceneNode::IsRegisteredForSelection(MochaEventType eventToCatch)
/*********************************************/
{
    return(EventRegister().IsRegisteredForSelection(eventToCatch));
}
/*********************************************/
char CSceneNode::LastKeyDown()
/*********************************************/
{
    return(CurrentSceneManager()->LastKeyDown());
}

/*********************************************/
char CSceneNode::LastKeyUp()
/*********************************************/
{
    return(CurrentSceneManager()->LastKeyUp());
}

/*********************************************/
bool CSceneNode::LockEvent(MochaEventType eventType)
/*********************************************/
{
    return(CurrentSceneManager()->LockEvent(this, eventType));
}

/*********************************************/
CDevicePoint CSceneNode::PreviousMousePosition()
/*********************************************/
{
    return(CurrentSceneManager()->PreviousMousePosition());
}

/*********************************************/
void CSceneNode::Register(MochaEventType eventToCatch, bool onlyOnSelection)
/*********************************************/
{
    EventRegister().Register(eventToCatch, onlyOnSelection);
}

/**********************************************/
bool CSceneNode::RemoveChild(CSceneNode *child)
/**********************************************/
{
    if(!(Contains(Children(), child)))
        return(false);
    else
    {
        Children(Remove(Children(), child));
        return(true);
    }
}

/*****************************************/
CCartesianPoint CSceneNode::ToCartesian(const CDevicePoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToCartesian(p));
}

/*****************************************/
CCartesianPoint CSceneNode::ToCartesian(const CGeographicalPoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToCartesian(p));
}

/*****************************************/
CartesianPointList CSceneNode::ToCartesian(const DevicePointList& points)
/*****************************************/
{
    return(CurrentSceneManager()->ToCartesian(points));
}

/*****************************************/
CartesianPointList CSceneNode::ToCartesian(const GeographicalPointList& points)
/*****************************************/
{
    return(CurrentSceneManager()->ToCartesian(points));
}

/*****************************************/
CDevicePoint CSceneNode::ToDevice(const CCartesianPoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToDevice(p));
}

/*****************************************/
CDevicePoint CSceneNode::ToDevice(const CGeographicalPoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToDevice(p));
}

/*****************************************/
DevicePointList CSceneNode::ToDevice(const CartesianPointList& points)
/*****************************************/
{
    return(CurrentSceneManager()->ToDevice(points));
}

/*****************************************/
DevicePointList CSceneNode::ToDevice(const GeographicalPointList& points)
/*****************************************/
{
    return(CurrentSceneManager()->ToDevice(points));
}

/*****************************************/
CGeographicalPoint CSceneNode::ToGeographical(const CCartesianPoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToGeographical(p));
}

/*****************************************/
CGeographicalPoint CSceneNode::ToGeographical(const CDevicePoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToGeographical(p));
}

/*********************************************/
GeographicalPointList CSceneNode::ToGeographical(const CartesianPointList& points)
/*********************************************/
{
    return(CurrentSceneManager()->ToGeographical(points));
}

/*********************************************/
GeographicalPointList CSceneNode::ToGeographical(const DevicePointList& points)
/*********************************************/
{
    return(CurrentSceneManager()->ToGeographical(points));
}

/*********************************************/
bool CSceneNode::UnlockEvent(MochaEventType eventType)
/*********************************************/
{
    return(CurrentSceneManager()->UnlockEvent(this, eventType));
}

/*********************************************/
void CSceneNode::Unregister(MochaEventType eventToDisable)
/*********************************************/
{
    EventRegister().Unregister(eventToDisable);
}

/*********************************************/
int CSceneNode::WindowXPosition()
/*********************************************/
{
    return(CurrentSceneManager()->WindowXPosition());
}

/*********************************************/
int CSceneNode::WindowYPosition()
/*********************************************/
{
    return(CurrentSceneManager()->WindowYPosition());
}

/*********************************************/
int CSceneNode::WindowWidth()
/*********************************************/
{
    return(CurrentSceneManager()->WindowWidth());
}

/*********************************************/
int CSceneNode::WindowHeight()
/*********************************************/
{
    return(CurrentSceneManager()->WindowHeight());
}



};
