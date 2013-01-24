/*****************************************************************************/
// Filename: SceneManager.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef SCENE_MANAGER_H_DEFINED
#define SCENE_MANAGER_H_DEFINED

#include <MochaObject.h>
#include <Color.h>
#include <map>
using std::map;

namespace Mocha
{

typedef map<MochaEventType, CSceneNode*> EventToNodeLockMap;

class CSceneNode;
class CSceneManager : public CMochaObject
{
    friend class CEventInterface;
    friend class CGraphVisitor;
    friend class CSceneNode;

    public:
        CSceneManager(CSceneNode* rootNode = NULL);
        virtual ~CSceneManager();

        void                         RenderScene();

        CColor                       BackgroundColor() const;
        void                         BackgroundColor(const CColor& color);
        double                       CartesianExtentBottom();
        double                       CartesianExtentLeft();
        double                       CartesianExtentRight();
        double                       CartesianExtentTop();
        double                       CartesianToDeviceScaleXAxis();
        double                       CartesianToDeviceScaleYAxis();
        CDevicePoint                 CurrentMousePosition();
        template <typename T> double Distance(const T& p1, const T& p2)
        {
            double a = p1.X() - p2.X();
            double b = p1.Y() - p2.Y();
            return(sqrt(a*a + b*b));
        }
        CSceneNode*                  EventLockHolder(MochaEventType eventType);
        double                       GreatCircleDistanceInMeters(const CGeographicalPoint& p1, const CGeographicalPoint& p2);
        void                         InvalidateScene();
        bool                         IsLeftMouseButtonDown();
        bool                         IsRightMouseButtonDown();
        bool                         IsSceneInvalid();
        char                         LastKeyDown();
        char                         LastKeyUp();
        bool                         LockEvent(CSceneNode* lockRequestor, MochaEventType eventToLock);
        CDevicePoint                 PreviousMousePosition();
        void                         RootNode(CSceneNode* node);
        CCartesianPoint              ToCartesian(const CDevicePoint& p);
        CCartesianPoint              ToCartesian(const CGeographicalPoint& p);
        CartesianPointList           ToCartesian(const DevicePointList& points);
        CartesianPointList           ToCartesian(const GeographicalPointList& points);
        CDevicePoint                 ToDevice(const CCartesianPoint& p);
        CDevicePoint                 ToDevice(const CGeographicalPoint& p);
        DevicePointList              ToDevice(const CartesianPointList& points);
        DevicePointList              ToDevice(const GeographicalPointList& points);
        CGeographicalPoint           ToGeographical(const CCartesianPoint& p);
        CGeographicalPoint           ToGeographical(const CDevicePoint& p);
        GeographicalPointList        ToGeographical(const CartesianPointList& points);
        GeographicalPointList        ToGeographical(const DevicePointList& points);
        bool                         UnlockEvent(CSceneNode* lockHolder, MochaEventType eventToUnlock);
        int                          WindowXPosition();
        int                          WindowYPosition();
        int                          WindowHeight();
        int                          WindowWidth();

    private:
        BoundAreaNodeStack&          BoundAreaStack(){return(_boundAreaStack);}
        CBoundAreaNode*              CurrentBoundArea();
        CMapSystemNode&              CurrentMapSystem();
        void                         CurrentMousePosition(CDevicePoint mousePos);
        CProjectionNode&             CurrentProjection();
        EventToNodeLockMap&          EventLockMap();
        void                         InitializeSceneProperties();
        void                         InitializeStacks();
        void                         IsLeftMouseButtonDown(bool isIt);
        void                         IsRightMouseButtonDown(bool isIt);
        void                         IsSceneInvalid(bool isIt);
        void                         LastKeyDown(char c);
        void                         LastKeyUp(char c);
        MapSystemNodeStack&          MapSystemStack(){return(_mapSystemStack);}
        void                         OnLeftMouseDown(CDevicePoint mousePos);
        void                         OnLeftMouseDoubleClick(CDevicePoint mousePos);
        void                         OnLeftMouseUp(CDevicePoint mousePos);
        void                         OnMouseMove(CDevicePoint mousePos);
        void                         OnRightMouseDown(CDevicePoint mousePos);
        void                         OnRightMouseDoubleClick(CDevicePoint mousePos);
        void                         OnRightMouseUp(CDevicePoint mousePos);
        void                         OnKeyDown(char c);
        void                         OnKeyUp(char c);
        void                         OnMove(int newX, int newY);
        void                         OnPrerender();
        void                         OnRender();
        void                         OnResize(int newWidth, int newHeight);
        void                         OnUpdate();
        void                         PrepareForRender(); //PREPARE FOR GLOOOORY!!!! AAAHOOOOO!!!
        void                         PreviousMousePosition(CDevicePoint mousePos);
        ProjectionNodeStack&         ProjectionStack(){return(_projectionStack);}
        CSceneNode*                  RootNode();
        void                         WindowXPosition(int xPos);
        void                         WindowYPosition(int yPos);
        void                         WindowHeight(int height);
        void                         WindowWidth(int width);

    private:
        CColor                      _backgroundColor;
        BoundAreaNodeStack          _boundAreaStack;
        CDevicePoint                _currentMousePosition;
        EventToNodeLockMap          _eventLockMap;
        bool                        _isLeftMouseButtonDown;
        bool                        _isRightMouseButtonDown;
        bool                        _isSceneInvalid;
        char                        _lastKeyDown;
        char                        _lastKeyUp;
        CDevicePoint                _previousMousePosition;
        MapSystemNodeStack          _mapSystemStack;
        ProjectionNodeStack         _projectionStack;
        CSceneNode*                 _rootNode;
        int                         _windowXPosition;
        int                         _windowYPosition;
        int                         _windowWidth;
        int                         _windowHeight;
};


};

#endif
