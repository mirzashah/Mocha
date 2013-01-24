#include <GraphVisitor.h>
#include <SceneNode.h>
#include <SceneManager.h>

namespace Mocha
{
/*****************************************/
CGraphVisitor::CGraphVisitor(CSceneNode* rootNode) :
_rootNode(rootNode)
/*****************************************/
{
}

/*****************************************/
CGraphVisitor::~CGraphVisitor()
/*****************************************/
{
}

/*****************************************/
BoundAreaNodeStack& CGraphVisitor::BoundAreaStack()
/*****************************************/
{
    return(CurrentSceneManager()->BoundAreaStack());
}

/*****************************************/
double CGraphVisitor::CartesianExtentBottom()
/*****************************************/
{
    return(CurrentSceneManager()->CartesianExtentBottom());
}

/*****************************************/
double CGraphVisitor::CartesianExtentLeft()
/*****************************************/
{
    return(CurrentSceneManager()->CartesianExtentLeft());
}

/*****************************************/
double CGraphVisitor::CartesianExtentRight()
/*****************************************/
{
    return(CurrentSceneManager()->CartesianExtentRight());
}

/*****************************************/
double CGraphVisitor::CartesianExtentTop()
/*****************************************/
{
    return(CurrentSceneManager()->CartesianExtentTop());
}
/*****************************************/
CProjectionNode& CGraphVisitor::CurrentProjection()
/*****************************************/
{
    return(CurrentSceneManager()->CurrentProjection());
}

/*****************************************/
CBoundAreaNode* CGraphVisitor::CurrentBoundArea()
/*****************************************/
{
    return(CurrentSceneManager()->CurrentBoundArea());
}

/*****************************************/
CMapSystemNode& CGraphVisitor::CurrentMapSystem()
/*****************************************/
{
    return(CurrentSceneManager()->CurrentMapSystem());
}

/*****************************************/
CDevicePoint CGraphVisitor::CurrentMousePosition()
/*****************************************/
{
    return(CurrentSceneManager()->CurrentMousePosition());
}

/*****************************************/
bool CGraphVisitor::IsLeftMouseButtonDown()
/*****************************************/
{
    return(CurrentSceneManager()->IsLeftMouseButtonDown());
}

/*****************************************/
bool CGraphVisitor::IsRightMouseButtonDown()
/*****************************************/
{
    return(CurrentSceneManager()->IsRightMouseButtonDown());
}

/*****************************************/
char CGraphVisitor::LastKeyDown()
/*****************************************/
{
    return(CurrentSceneManager()->LastKeyDown());
}

/*****************************************/
char CGraphVisitor::LastKeyUp()
/*****************************************/
{
    return(CurrentSceneManager()->LastKeyUp());
}

/*****************************************/
MapSystemNodeStack& CGraphVisitor::MapSystemStack()
/*****************************************/
{
    return(CurrentSceneManager()->MapSystemStack());
}

/*****************************************/
void CGraphVisitor::PerformOperation(CBoundAreaNode& node)
/*****************************************/
{
    PerformOperation((CSceneNode&)(node));
}

/*****************************************/
void CGraphVisitor::PerformOperation(CDOFNode& node)
/*****************************************/
{
    PerformOperation((CSceneNode&)(node));
}

/*****************************************/
void CGraphVisitor::PerformOperation(CGeoNode& node)
/*****************************************/
{
    PerformOperation((CSceneNode&)(node));
}

/*****************************************/
void CGraphVisitor::PerformOperation(CMapSystemNode& node)
/*****************************************/
{
    PerformOperation((CSceneNode&)(node));
}

/*****************************************/
void CGraphVisitor::PerformOperation(CProjectionNode& node)
/*****************************************/
{
    PerformOperation((CSceneNode&)(node));
}

/*****************************************/
ProjectionNodeStack& CGraphVisitor::ProjectionStack()
/*****************************************/
{
    return(CurrentSceneManager()->ProjectionStack());
}

/*****************************************/
CSceneNode* CGraphVisitor::RootNode()
/*****************************************/
{
    return(_rootNode);
}

/*****************************************/
CCartesianPoint CGraphVisitor::ToCartesian(const CDevicePoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToCartesian(p));
}

/*****************************************/
CCartesianPoint CGraphVisitor::ToCartesian(const CGeographicalPoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToCartesian(p));
}

/*****************************************/
CDevicePoint CGraphVisitor::ToDevice(const CCartesianPoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToDevice(p));
}

/*****************************************/
CDevicePoint CGraphVisitor::ToDevice(const CGeographicalPoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToDevice(p));
}

/*****************************************/
CGeographicalPoint CGraphVisitor::ToGeographical(const CCartesianPoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToGeographical(p));
}

/*****************************************/
CGeographicalPoint CGraphVisitor::ToGeographical(const CDevicePoint& p)
/*****************************************/
{
    return(CurrentSceneManager()->ToGeographical(p));
}

/*****************************************/
int CGraphVisitor::WindowXPosition()
/*****************************************/
{
    return(CurrentSceneManager()->WindowXPosition());
}

/*****************************************/
int CGraphVisitor::WindowYPosition()
/*****************************************/
{
    return(CurrentSceneManager()->WindowYPosition());
}

/*****************************************/
int CGraphVisitor::WindowHeight()
/*****************************************/
{
    return(CurrentSceneManager()->WindowHeight());
}

/*****************************************/
int CGraphVisitor::WindowWidth()
/*****************************************/
{
    return(CurrentSceneManager()->WindowWidth());
}

};
