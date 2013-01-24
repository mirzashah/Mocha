/*****************************************************************************/
// Filename: GraphVisitor.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef GRAPH_VISITOR_H_DEFINED
#define GRAPH_VISITOR_H_DEFINED

#include <MochaObject.h>

namespace Mocha
{

class CBoundAreaNode;
class CDOFNode;
class CGeoNode;
class CMapSystemNode;
class CSceneNode;
class CProjectionNode;
class CGraphVisitor : public CMochaObject
{
    public:
        CGraphVisitor(CSceneNode* rootNode);
        virtual ~CGraphVisitor();

        virtual void         Run()                                    = 0;

        virtual void         PerformOperation(CBoundAreaNode& node);
        virtual void         PerformOperation(CDOFNode& node);
        virtual void         PerformOperation(CGeoNode& node);
        virtual void         PerformOperation(CMapSystemNode& node);
        virtual void         PerformOperation(CProjectionNode& node);
        virtual void         PerformOperation(CSceneNode& node)       = 0;

    protected:
        CSceneNode*          RootNode();

    protected:
        BoundAreaNodeStack&  BoundAreaStack();
        double               CartesianExtentBottom();
        double               CartesianExtentLeft();
        double               CartesianExtentRight();
        double               CartesianExtentTop();
        CProjectionNode&     CurrentProjection();
        CBoundAreaNode*      CurrentBoundArea();
        CMapSystemNode&      CurrentMapSystem();
        CDevicePoint         CurrentMousePosition();
        bool                 IsLeftMouseButtonDown();
        bool                 IsRightMouseButtonDown();
        char                 LastKeyDown();
        char                 LastKeyUp();
        MapSystemNodeStack&  MapSystemStack();
        ProjectionNodeStack& ProjectionStack();
        CCartesianPoint      ToCartesian(const CDevicePoint& p);
        CCartesianPoint      ToCartesian(const CGeographicalPoint& p);
        CDevicePoint         ToDevice(const CCartesianPoint& p);
        CDevicePoint         ToDevice(const CGeographicalPoint& p);
        CGeographicalPoint   ToGeographical(const CCartesianPoint& p);
        CGeographicalPoint   ToGeographical(const CDevicePoint& p);
        int                  WindowXPosition();
        int                  WindowYPosition();
        int                  WindowHeight();
        int                  WindowWidth();

    private:
        CSceneNode*         _rootNode;
};

};

#endif
