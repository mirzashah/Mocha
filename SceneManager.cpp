#include <SceneManager.h>
#include <EventInterface.h>
#include <ProjectionNode.h>
#include <BoundAreaNode.h>
#include <MapSystemNode.h>
#include <RenderVisitor.h>
#include <EventVisitor.h>
#include <RectangleBoundAreaNode.h>

namespace Mocha
{
/*****************************************/
CSceneManager::CSceneManager(CSceneNode* rootNode) :
_rootNode(rootNode)
/*****************************************/
{
    InitializeSceneProperties();
    InitializeStacks();
}

/*****************************************/
CSceneManager::~CSceneManager()
/*****************************************/
{
}

/*****************************************/
CColor CSceneManager::BackgroundColor() const
/*****************************************/
{
    return(_backgroundColor);
}

/*****************************************/
void CSceneManager::BackgroundColor(const CColor& color)
/*****************************************/
{
    _backgroundColor = color;
}

/*****************************************/
double CSceneManager::CartesianExtentBottom()
/*****************************************/
{
    return(CurrentProjection().Bottom());
}

/*****************************************/
double CSceneManager::CartesianExtentLeft()
/*****************************************/
{
    return(CurrentProjection().Left());
}

/*****************************************/
double CSceneManager::CartesianExtentRight()
/*****************************************/
{
    return(CurrentProjection().Right());
}

/*****************************************/
double CSceneManager::CartesianExtentTop()
/*****************************************/
{
    return(CurrentProjection().Top());
}

/*****************************************/
double CSceneManager::CartesianToDeviceScaleXAxis()
/*****************************************/
{
    return((CartesianExtentRight()-CartesianExtentLeft()) / WindowWidth());
}

/*****************************************/
double CSceneManager::CartesianToDeviceScaleYAxis()
/*****************************************/
{
    return((CartesianExtentTop()-CartesianExtentBottom()) / WindowHeight());
}

/*****************************************/
CBoundAreaNode* CSceneManager::CurrentBoundArea()
/*****************************************/
{
    if(BoundAreaStack().size() <= 0)
        return(NULL);
    else
        return(BoundAreaStack().top());
}

/*****************************************/
CMapSystemNode& CSceneManager::CurrentMapSystem()
/*****************************************/
{
    return(*(MapSystemStack().top()));
}

/*****************************************/
CProjectionNode& CSceneManager::CurrentProjection()
/*****************************************/
{
    return(*(ProjectionStack().top()));
}

/*****************************************/
void CSceneManager::InitializeStacks()
/*****************************************/
{
    ProjectionStack().push(new CProjectionNode(-100,100,100,-100));
    MapSystemStack().push(new CMapSystemNode(WGS_84, MERCATOR, CLatLongPoint(0,0)));
}

/*****************************************/
CDevicePoint CSceneManager::CurrentMousePosition()
/*****************************************/
{
    return(_currentMousePosition);
}

/*****************************************/
void CSceneManager::CurrentMousePosition(CDevicePoint mousePos)
/*****************************************/
{
    _currentMousePosition = mousePos;
}

/*****************************************/
CSceneNode* CSceneManager::EventLockHolder(MochaEventType eventType)
/*****************************************/
{
    return(EventLockMap()[eventType]);
}

/*****************************************/
EventToNodeLockMap& CSceneManager::EventLockMap()
/*****************************************/
{
    return(_eventLockMap);
}

/*****************************************/
double CSceneManager::GreatCircleDistanceInMeters(const CGeographicalPoint& p1, const CGeographicalPoint& p2)
/*****************************************/
{
    return(CurrentMapSystem().ReferenceEllipsoid().DistanceBetweenTwoPoints(p1, p2));
}

/*****************************************/
void CSceneManager::InitializeSceneProperties()
/*****************************************/
{
    InvalidateScene();
    WindowXPosition(0);
    WindowYPosition(0);
    WindowHeight(1);
    WindowWidth(1);
    CurrentMousePosition(CDevicePoint(0,0));
    PreviousMousePosition(CDevicePoint(0,0));
    LastKeyDown(0);
    LastKeyUp(0);
    IsLeftMouseButtonDown(false);
    IsRightMouseButtonDown(false);
}

/*****************************************/
void CSceneManager::InvalidateScene()
/*****************************************/
{
    IsSceneInvalid(true);
}

/*****************************************/
bool CSceneManager::IsLeftMouseButtonDown()
/*****************************************/
{
    return(_isLeftMouseButtonDown);
}

/*****************************************/
void CSceneManager::IsLeftMouseButtonDown(bool isIt)
/*****************************************/
{
    _isLeftMouseButtonDown = isIt;
}

/*****************************************/
bool CSceneManager::IsRightMouseButtonDown()
/*****************************************/
{
    return(_isRightMouseButtonDown);
}

/*****************************************/
void CSceneManager::IsRightMouseButtonDown(bool isIt)
/*****************************************/
{
    _isRightMouseButtonDown = isIt;
}

/*****************************************/
bool CSceneManager::IsSceneInvalid()
/*****************************************/
{
    return(_isSceneInvalid);
}

/*****************************************/
void CSceneManager::IsSceneInvalid(bool isIt)
/*****************************************/
{
    _isSceneInvalid = isIt;
}

/*****************************************/
char CSceneManager::LastKeyDown()
/*****************************************/
{
    return(_lastKeyDown);
}

/*****************************************/
void CSceneManager::LastKeyDown(char c)
/*****************************************/
{
    _lastKeyDown = c;
}

/*****************************************/
char CSceneManager::LastKeyUp()
/*****************************************/
{
    return(_lastKeyUp);
}

/*****************************************/
void CSceneManager::LastKeyUp(char c)
/*****************************************/
{
    _lastKeyUp = c;
}

/*****************************************/
bool CSceneManager::LockEvent(CSceneNode* lockRequestor, MochaEventType eventToLock)
/*****************************************/
{
    //The lock has to be available or already locked by the same requestor, AND the node has to be registered for that particular event
    if((EventLockMap()[eventToLock]==NULL || EventLockMap()[eventToLock]==lockRequestor) && lockRequestor->IsRegistered(eventToLock))
    {
        EventLockMap()[eventToLock] = lockRequestor;
        return(true);
    }
    else
        return(false);
}

/*****************************************/
void CSceneManager::OnLeftMouseDown(CDevicePoint mousePos)
/*****************************************/
{
    CurrentSceneManager(this);
    CurrentMousePosition(mousePos);
    IsLeftMouseButtonDown(true);
    CEventVisitor(RootNode(), ME_MOUSE_LEFT_DOWN).Run();
}

/*****************************************/
void CSceneManager::OnLeftMouseDoubleClick(CDevicePoint mousePos)
/*****************************************/
{
    CurrentSceneManager(this);
    CurrentMousePosition(mousePos);
    IsLeftMouseButtonDown(false);
    CEventVisitor(RootNode(), ME_MOUSE_LEFT_DOUBLECLICK).Run();
}

/*****************************************/
void CSceneManager::OnLeftMouseUp(CDevicePoint mousePos)
/*****************************************/
{
    CurrentSceneManager(this);
    CurrentMousePosition(mousePos);
    IsLeftMouseButtonDown(false);
    CEventVisitor(RootNode(), ME_MOUSE_LEFT_UP).Run();
}

/*****************************************/
void CSceneManager::OnMouseMove(CDevicePoint mousePos)
/*****************************************/
{
    CurrentSceneManager(this);
    PreviousMousePosition(CurrentMousePosition());
    CurrentMousePosition(mousePos);
    CEventVisitor(RootNode(), ME_MOUSE_MOVE).Run();
}

/*****************************************/
void CSceneManager::OnRightMouseDown(CDevicePoint mousePos)
/*****************************************/
{
    CurrentSceneManager(this);
    CurrentMousePosition(mousePos);
    IsRightMouseButtonDown(true);
    CEventVisitor(RootNode(), ME_MOUSE_RIGHT_DOWN).Run();
}

/*****************************************/
void CSceneManager::OnRightMouseDoubleClick(CDevicePoint mousePos)
/*****************************************/
{
    CurrentSceneManager(this);
    CurrentMousePosition(mousePos);
    IsRightMouseButtonDown(false);
    CEventVisitor(RootNode(), ME_MOUSE_RIGHT_DOUBLECLICK).Run();
}

/*****************************************/
void CSceneManager::OnRightMouseUp(CDevicePoint mousePos)
/*****************************************/
{
    CurrentSceneManager(this);
    CurrentMousePosition(mousePos);
    IsRightMouseButtonDown(false);
    CEventVisitor(RootNode(), ME_MOUSE_RIGHT_UP).Run();
}

/*****************************************/
void CSceneManager::OnKeyDown(char c)
/*****************************************/
{
    CurrentSceneManager(this);
    LastKeyDown(c);
    CEventVisitor(RootNode(), ME_KEY_DOWN).Run();
}

/*****************************************/
void CSceneManager::OnKeyUp(char c)
/*****************************************/
{
    CurrentSceneManager(this);
    LastKeyUp(c);
    CEventVisitor(RootNode(), ME_KEY_UP).Run();
}

/*****************************************/
void CSceneManager::OnMove(int newX, int newY)
/*****************************************/
{
    CurrentSceneManager(this);
    WindowXPosition(newX);
    WindowYPosition(newY);
    CEventVisitor(RootNode(), ME_WINDOW_MOVE).Run();
}

/*****************************************/
void CSceneManager::OnPrerender()
/*****************************************/
{
    CurrentSceneManager(this);
    CEventVisitor(RootNode(), ME_PRERENDER).Run();
}

/*****************************************/
void CSceneManager::OnRender()
/*****************************************/
{
    RenderScene();
}

/*****************************************/
void CSceneManager::OnResize(int newWidth, int newHeight)
/*****************************************/
{
    CurrentSceneManager(this);
    WindowWidth(newWidth);
    WindowHeight(newHeight);
    CEventVisitor(RootNode(), ME_WINDOW_RESIZE).Run();
    InvalidateScene();
}

/*****************************************/
void CSceneManager::OnUpdate()
/*****************************************/
{
    CurrentSceneManager(this);
    CEventVisitor(RootNode(), ME_UPDATE).Run();
}

/*****************************************/
void CSceneManager::PrepareForRender()
/*****************************************/
{
    CurrentSceneManager(this);

    /*TODO: The following need to only be called once, maybe we can move them out. I don't think
    it should affect performance though, it's just setting a bunch of bitmasks*/
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LINE_SMOOTH | GL_BLEND);
    glDisable(GL_DEPTH_TEST);

    CColor backgroundColor = BackgroundColor();
    float r = (float)(backgroundColor.Red())/255.0f;
    float g = (float)(backgroundColor.Green())/255.0f;
    float b = (float)(backgroundColor.Blue())/255.0f;
    float a = (float)(backgroundColor.Alpha())/255.0f;
    glClearColor(r, g, b, a);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glEnable(GL_TEXTURE_2D);
    /*End TODO*/

    glViewport(0,0, WindowWidth(), WindowHeight()); //Setup viewport, use entire window. TODO: Configurable viewport?
    CurrentProjection().ApplyProjection();          //Apply default projection. Projection stack should have only one item.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
}

/*****************************************/
CDevicePoint CSceneManager::PreviousMousePosition()
/*****************************************/
{
    return(_previousMousePosition);
}

/*****************************************/
void CSceneManager::PreviousMousePosition(CDevicePoint pos)
/*****************************************/
{
    _previousMousePosition = pos;
}

/*****************************************/
CSceneNode* CSceneManager::RootNode()
/*****************************************/
{
    return(_rootNode);
}

/*****************************************/
void CSceneManager::RootNode(CSceneNode* node)
/*****************************************/
{
    _rootNode = node;
}

/*****************************************/
void CSceneManager::RenderScene()
/*****************************************/
{
    CurrentSceneManager(this);
    PrepareForRender();
    CRenderVisitor(RootNode()).Run();
    IsSceneInvalid(false);
}

/*****************************************/
CCartesianPoint CSceneManager::ToCartesian(const CDevicePoint& p)
/*****************************************/
{
    double xCart, yCart, zCart;
    GLdouble modelMatrix[16];
    GLdouble projMatrix[16];
    GLint viewport[4];
    glGetDoublev(GL_MODELVIEW_MATRIX, modelMatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);
    glGetIntegerv(GL_VIEWPORT, viewport);

    gluUnProject(p.X(), p.Y(), 0, modelMatrix, projMatrix, viewport, &xCart, &yCart, &zCart);
    return(CCartesianPoint(xCart,yCart));
}

/*********************************************/
CCartesianPoint CSceneManager::ToCartesian(const CGeographicalPoint& p)
/*********************************************/
{
    return(CurrentMapSystem().Projection().ProjectPoint(p, CurrentMapSystem().ReferenceEllipsoid()));
}

/*****************************************/
CartesianPointList CSceneManager::ToCartesian(const DevicePointList& points)
/*****************************************/
{
    DevicePointList::const_iterator itr;
    CartesianPointList toReturn;
    for(itr = points.begin(); itr != points.end(); itr++)
        toReturn.push_back(ToCartesian(*itr));
    return(toReturn);
}

/*****************************************/
CartesianPointList CSceneManager::ToCartesian(const GeographicalPointList& points)
/*****************************************/
{
    GeographicalPointList::const_iterator itr;
    CartesianPointList toReturn;
    for(itr = points.begin(); itr != points.end(); itr++)
        toReturn.push_back(ToCartesian(*itr));
    return(toReturn);
}

/*****************************************/
CDevicePoint CSceneManager::ToDevice(const CCartesianPoint& p)
/*****************************************/
{
    double xDev, yDev, zDev;
    GLdouble modelMatrix[16];
    GLdouble projMatrix[16];
    GLint viewport[4];
    glGetDoublev(GL_MODELVIEW_MATRIX, modelMatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);
    glGetIntegerv(GL_VIEWPORT, viewport);

    gluProject(p.X(), p.Y(), 0, modelMatrix, projMatrix, viewport, &xDev, &yDev, &zDev);
    return(CDevicePoint((int)xDev,(int)yDev));
}

/*****************************************/
CDevicePoint CSceneManager::ToDevice(const CGeographicalPoint& p)
/*****************************************/
{
    return(ToDevice(ToCartesian(p)));
}

/*****************************************/
DevicePointList CSceneManager::ToDevice(const CartesianPointList& points)
/*****************************************/
{
    CartesianPointList::const_iterator itr;
    DevicePointList toReturn;
    for(itr = points.begin(); itr != points.end(); itr++)
        toReturn.push_back(ToDevice(*itr));
    return(toReturn);
}

/*****************************************/
DevicePointList CSceneManager::ToDevice(const GeographicalPointList& points)
/*****************************************/
{
    GeographicalPointList::const_iterator itr;
    DevicePointList toReturn;
    for(itr = points.begin(); itr != points.end(); itr++)
        toReturn.push_back(ToDevice(*itr));
    return(toReturn);
}

/*********************************************/
CGeographicalPoint CSceneManager::ToGeographical(const CCartesianPoint& p)
/*********************************************/
{
    return(CurrentMapSystem().Projection().InverseProjectPoint(p, CurrentMapSystem().ReferenceEllipsoid()));
}

/*********************************************/
CGeographicalPoint CSceneManager::ToGeographical(const CDevicePoint& p)
/*********************************************/
{
    return(ToGeographical(ToCartesian(p)));
}

/*********************************************/
GeographicalPointList CSceneManager::ToGeographical(const CartesianPointList& points)
/*********************************************/
{
    CartesianPointList::const_iterator itr;
    GeographicalPointList toReturn;
    for(itr = points.begin(); itr != points.end(); itr++)
        toReturn.push_back(ToGeographical(*itr));
    return(toReturn);
}

/*********************************************/
GeographicalPointList CSceneManager::ToGeographical(const DevicePointList& points)
/*********************************************/
{
    DevicePointList::const_iterator itr;
    GeographicalPointList toReturn;
    for(itr = points.begin(); itr != points.end(); itr++)
        toReturn.push_back(ToGeographical(*itr));
    return(toReturn);
}

/*****************************************/
bool CSceneManager::UnlockEvent(CSceneNode* lockHolder, MochaEventType eventToUnlock)
/*****************************************/
{
    if(EventLockMap()[eventToUnlock]==lockHolder)
    {
        EventLockMap()[eventToUnlock] = NULL;
        return(true);
    }
    else
        return(false);
}

/*****************************************/
int CSceneManager::WindowXPosition()
/*****************************************/
{
    return(_windowXPosition);
}

/*****************************************/
void CSceneManager::WindowXPosition(int xPos)
/*****************************************/
{
    _windowXPosition = xPos;
}

/*****************************************/
int CSceneManager::WindowYPosition()
/*****************************************/
{
    return(_windowYPosition);
}

/*****************************************/
void CSceneManager::WindowYPosition(int yPos)
/*****************************************/
{
    _windowYPosition = yPos;
}

/*****************************************/
int CSceneManager::WindowHeight()
/*****************************************/
{
    return(_windowHeight);
}

/*****************************************/
void CSceneManager::WindowHeight(int height)
/*****************************************/
{
    _windowHeight = height;
}

/*****************************************/
int CSceneManager::WindowWidth()
/*****************************************/
{
    return(_windowWidth);
}

/*****************************************/
void CSceneManager::WindowWidth(int width)
/*****************************************/
{
    _windowWidth = width;
}

};
