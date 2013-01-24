/*****************************************************************************/
// Filename: SceneNode.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef SCENE_NODE_H_DEFINED
#define SCENE_NODE_H_DEFINED

#include <MochaObject.h>
#include <EventRegister.h>
#include <SceneManager.h>

namespace Mocha
{

class CGraphVisitor;
class CProjectionNode;
class CMapSystemNode;
class CBoundAreaNode;
class CSceneNodeCollection;
class CSceneNode : public CMochaObject
{
    friend class CEventVisitor;
    friend class CRenderVisitor;
    friend class CUpdateVisitor;
    friend class CSceneManager;

    public:
        CSceneNode();
        virtual ~CSceneNode();

        bool                   AddChild(CSceneNode* child);
        bool                   AddChild(CSceneNodeCollection* child);
        bool                   RemoveChild(CSceneNode* child);
        SceneNodeList          Children();

    protected:
        virtual void           InjectVisitor(CGraphVisitor& visitor) = 0;

    protected: //Event handlers and management

        bool                   IsRegistered(MochaEventType eventToCatch);
        bool                   IsRegisteredForSelection(MochaEventType eventToCatch);
        bool                   LockEvent(MochaEventType eventType);
        virtual void           OnKeyDown(unsigned int hitNumber){}
        virtual void           OnKeyUp(unsigned int hitNumber){}
        virtual void           OnLeftMouseDown(unsigned int hitNumber){}
        virtual void           OnLeftMouseDoubleClick(unsigned int hitNumber){}
        virtual void           OnLeftMouseUp(unsigned int hitNumber){}
        virtual void           OnMouseMove(unsigned int hitNumber){}
        virtual void           OnPrerender(){}
        virtual void           OnRightMouseDown(unsigned int hitNumber){}
        virtual void           OnRightMouseDoubleClick(unsigned int hitNumber){}
        virtual void           OnRightMouseUp(unsigned int hitNumber){}
        virtual void           OnUpdate(){}
        virtual void           OnWindowMove(){}
        virtual void           OnWindowResize(){}
        void                   Register(MochaEventType eventToCatch, bool onlyOnSelection);
        bool                   UnlockEvent(MochaEventType eventType);
        void                   Unregister(MochaEventType eventToDisable);

    protected: //Scene Information + Transform Functions
        double                 CartesianExtentBottom();
        double                 CartesianExtentLeft();
        double                 CartesianExtentRight();
        double                 CartesianExtentTop();
        double                 CartesianToDeviceScaleXAxis();
        double                 CartesianToDeviceScaleYAxis();
        CDevicePoint           CurrentMousePosition();
        template <typename T> double Distance(const T& p1, const T& p2)
        {
            return(CurrentSceneManager()->Distance(p1,p2));
        }
        double                 GreatCircleDistanceInMeters(const CGeographicalPoint& p1, const CGeographicalPoint& p2);
        void                   InvalidateScene();
        bool                   IsLeftMouseButtonDown();
        bool                   IsRightMouseButtonDown();
        char                   LastKeyDown();
        char                   LastKeyUp();
        CDevicePoint           PreviousMousePosition();
        CCartesianPoint        ToCartesian(const CDevicePoint& p);
        CCartesianPoint        ToCartesian(const CGeographicalPoint& p);
        CartesianPointList     ToCartesian(const DevicePointList& points);
        CartesianPointList     ToCartesian(const GeographicalPointList& points);
        CDevicePoint           ToDevice(const CCartesianPoint& p);
        CDevicePoint           ToDevice(const CGeographicalPoint& p);
        DevicePointList        ToDevice(const CartesianPointList& points);
        DevicePointList        ToDevice(const GeographicalPointList& points);
        CGeographicalPoint     ToGeographical(const CCartesianPoint& p);
        CGeographicalPoint     ToGeographical(const CDevicePoint& p);
        GeographicalPointList  ToGeographical(const CartesianPointList& points);
        GeographicalPointList  ToGeographical(const DevicePointList& points);
        int                    WindowXPosition();
        int                    WindowYPosition();
        int                    WindowWidth();
        int                    WindowHeight();

    private:
        CProjectionNode&      CurrentProjection();
        CBoundAreaNode*        CurrentBoundArea();
        CMapSystemNode&        CurrentMapSystem();

    private:
        CEventRegister&        EventRegister();
        void                   Children(SceneNodeList children);

    private:
        SceneNodeList          _children;
        CEventRegister         _eventRegister;
};

};

#endif
