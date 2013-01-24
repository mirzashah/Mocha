#ifndef EVENT_VISITOR_H_DEFINED
#define EVENT_VISITOR_H_DEFINED

#include <GraphVisitor.h>

namespace Mocha
{

class CEventVisitor: public CGraphVisitor
{
    public:
        CEventVisitor(CSceneNode* rootNode, MochaEventType eventType);
        virtual ~CEventVisitor();

        virtual void Run();

    private:
        bool           AreWeOnWayUp();
        void           AreWeOnWayUp(bool areWe);
        void           DoTraversal();
        CSceneNode*    EventLockHolder(MochaEventType eventType);
        MochaEventType EventType();
        void           ExecuteTraversal(CSceneNode& current);
        bool           IsNodeRegisteredForEvent(CSceneNode& node);
        unsigned int   HitNumber();
        void           HitNumber(unsigned int num);
        bool           OnlyTargetNodeThatLockedEvent();
        void           OnlyTargetNodeThatLockedEvent(bool shouldWe);
        virtual void   PerformOperation(CBoundAreaNode& node);
        virtual void   PerformOperation(CDOFNode& node);
        virtual void   PerformOperation(CGeoNode& node);
        virtual void   PerformOperation(CMapSystemNode& node);
        virtual void   PerformOperation(CProjectionNode& node);
        virtual void   PerformOperation(CSceneNode& node);

    private:
        bool           _areWeOnWayUp;
        MochaEventType _eventType;
        unsigned int   _hitNumber;
        bool           _onlyTargetNodeThatLockedEvent;
};

};

#endif
