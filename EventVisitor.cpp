#include <EventVisitor.h>
#include <BoundAreaNode.h>
#include <DOFNode.h>
#include <GeoNode.h>
#include <MapSystemNode.h>
#include <ProjectionNode.h>
#include <SceneNode.h>
#include <SceneManager.h>
#include <MochaException.h>

namespace Mocha
{
/*****************************************/
CEventVisitor::CEventVisitor(CSceneNode* rootNode, MochaEventType eventType) :
CGraphVisitor(rootNode),
_eventType(eventType),
_hitNumber(0)
/*****************************************/
{
    AreWeOnWayUp(false);
    OnlyTargetNodeThatLockedEvent(false);
}

/*****************************************/
CEventVisitor::~CEventVisitor()
/*****************************************/
{
}

/*****************************************/
bool CEventVisitor::AreWeOnWayUp()
/*****************************************/
{
    return(_areWeOnWayUp);
}

/*****************************************/
void CEventVisitor::AreWeOnWayUp(bool areWe)
/*****************************************/
{
    _areWeOnWayUp = areWe;
}

/*****************************************/
void CEventVisitor::DoTraversal()
/*****************************************/
{
    HitNumber(0);
    CSceneNode& root = *(RootNode());
    ExecuteTraversal(root);
}

/*****************************************/
CSceneNode* CEventVisitor::EventLockHolder(MochaEventType eventType)
/*****************************************/
{
    return(CurrentSceneManager()->EventLockHolder(eventType));
}

/*****************************************/
MochaEventType CEventVisitor::EventType()
/*****************************************/
{
    return(_eventType);
}

/*****************************************/
void CEventVisitor::ExecuteTraversal(CSceneNode& current)
/*****************************************/
{
    AreWeOnWayUp(false);
    current.InjectVisitor(*this); //Inject on way down
    SceneNodeList children = Reverse(current.Children());
    for(unsigned int c=0; c<children.size(); c++)
    {
        ExecuteTraversal(*children.at(c));
    }
    AreWeOnWayUp(true);
    current.InjectVisitor(*this); //Inject again on way back up
}

/*****************************************/
unsigned int CEventVisitor::HitNumber()
/*****************************************/
{
    return(_hitNumber);
}

/*****************************************/
void CEventVisitor::HitNumber(unsigned int hitNumber)
/*****************************************/
{
    _hitNumber = hitNumber;
}

/*****************************************/
bool CEventVisitor::OnlyTargetNodeThatLockedEvent()
/*****************************************/
{
    return(_onlyTargetNodeThatLockedEvent);
}

/*****************************************/
void CEventVisitor::OnlyTargetNodeThatLockedEvent(bool shouldWe)
/*****************************************/
{
    _onlyTargetNodeThatLockedEvent = shouldWe;
}

/*****************************************/
void CEventVisitor::PerformOperation(CBoundAreaNode& node)
/*****************************************/
{
    if(!AreWeOnWayUp())
    {
        BoundAreaStack().push(&node);
    }
    else
    {
        CEventVisitor::PerformOperation((CSceneNode&)(node));
        BoundAreaStack().pop();
    }
}

/*****************************************/
void CEventVisitor::PerformOperation(CDOFNode& node)
/*****************************************/
{
    if(!(AreWeOnWayUp()))
    {
        node.ApplyTransformation();
    }
    else
    {
        CEventVisitor::PerformOperation((CSceneNode&)(node));
        node.UndoTransformation();
    }

}

/*****************************************/
void CEventVisitor::PerformOperation(CGeoNode& node)
/*****************************************/
{
    if(!AreWeOnWayUp())
    {
        if(node.OptionalBoundArea())
            BoundAreaStack().push(node.OptionalBoundArea());
    }
    else
    {
        CEventVisitor::PerformOperation((CSceneNode&)(node));
        if(node.OptionalBoundArea())
            BoundAreaStack().pop();
    }
}

/*****************************************/
void CEventVisitor::PerformOperation(CMapSystemNode& node)
/*****************************************/
{
    if(!AreWeOnWayUp())
    {
        MapSystemStack().push(&node);
    }
    else
    {
        CEventVisitor::PerformOperation((CSceneNode&)(node));
        MapSystemStack().pop();
    }

}

/*****************************************/
void CEventVisitor::PerformOperation(CProjectionNode& node)
/*****************************************/
{
    if(!AreWeOnWayUp())
    {
        ProjectionStack().push(&node);
        CurrentProjection().ApplyProjection();

    }
    else
    {
        CEventVisitor::PerformOperation((CSceneNode&)(node));
        ProjectionStack().pop();
        CurrentProjection().ApplyProjection();
    }
}

/*****************************************/
void CEventVisitor::PerformOperation(CSceneNode& node)
/*****************************************/
{
    if(IsNodeRegisteredForEvent(node))
    {
        if((!OnlyTargetNodeThatLockedEvent()) || (OnlyTargetNodeThatLockedEvent() && (&node == EventLockHolder(EventType()))))
        {
            HitNumber(HitNumber()+1);
            switch(EventType())
            {
                case ME_MOUSE_LEFT_DOWN:
                    node.OnLeftMouseDown(HitNumber());
                    break;
                case ME_MOUSE_LEFT_UP:
                    node.OnLeftMouseUp(HitNumber());
                    break;
                case ME_MOUSE_LEFT_DOUBLECLICK:
                    node.OnLeftMouseDoubleClick(HitNumber());
                    break;
                case ME_MOUSE_MOVE:
                    node.OnMouseMove(HitNumber());
                    break;
                case ME_MOUSE_RIGHT_DOWN:
                    node.OnRightMouseDown(HitNumber());
                    break;
                case ME_MOUSE_RIGHT_UP:
                    node.OnRightMouseUp(HitNumber());
                    break;
                case ME_MOUSE_RIGHT_DOUBLECLICK:
                    node.OnRightMouseDoubleClick(HitNumber());
                    break;
                case ME_KEY_DOWN:
                    node.OnKeyDown(HitNumber());
                    break;
                case ME_KEY_UP:
                    node.OnKeyUp(HitNumber());
                    break;
                case ME_WINDOW_RESIZE:
                    node.OnWindowResize();
                    break;
                case ME_WINDOW_MOVE:
                    node.OnWindowMove();
                    break;
                case ME_UPDATE:
                    node.OnUpdate();
                    break;
                case ME_PRERENDER:
                    node.OnPrerender();
                    break;
                default:
                    throw(CMochaException());
            };
        };
    };
}

/*****************************************/
bool CEventVisitor::IsNodeRegisteredForEvent(CSceneNode& node)
/*****************************************/
{
    bool toReturn = false;

    if(node.IsRegistered(EventType()))
    {
        if(node.IsRegisteredForSelection(EventType()))
        {
            if(CurrentBoundArea()==NULL)
                toReturn = true;
            else
                toReturn = (CurrentBoundArea()->IsMouseOverArea(ToCartesian(CurrentMousePosition())));
        }
        else
            toReturn = true;
    }

    return(toReturn);
}

/*****************************************/
void CEventVisitor::Run()
/*****************************************/
{
    if(!RootNode())
        return;

    //TODO: This got ugly kind of fast, and is not as efficient as I liked. The algorithm should run like this.
    //1. If no node has the event locked, we run as normal.
    //2. If a node does have the event lock, we should only call the handler for that node.
    //Note!!! No node should have the lock if it is not registered for that event. The locking calls ensure this.

    CSceneNode* lockHolder = EventLockHolder(EventType());
    if(lockHolder!=NULL)
        OnlyTargetNodeThatLockedEvent(true);
    else
        OnlyTargetNodeThatLockedEvent(false);

    DoTraversal();
}



};
