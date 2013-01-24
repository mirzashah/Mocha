#include <RenderVisitor.h>
#include <BoundAreaNode.h>
#include <DOFNode.h>
#include <GeoNode.h>
#include <MapSystemNode.h>
#include <ProjectionNode.h>
#include <SceneNode.h>
#include <MochaException.h>

namespace Mocha
{
/*****************************************/
CRenderVisitor::CRenderVisitor(CSceneNode* rootNode) :
CGraphVisitor(rootNode)
/*****************************************/
{
    AreWeOnWayUp(false);
}

/*****************************************/
CRenderVisitor::~CRenderVisitor()
/*****************************************/
{
}

/*****************************************/
bool CRenderVisitor::AreWeOnWayUp()
/*****************************************/
{
    return(_areWeOnWayUp);
}

/*****************************************/
void CRenderVisitor::AreWeOnWayUp(bool areWe)
/*****************************************/
{
    _areWeOnWayUp = areWe;
}

/*****************************************/
void CRenderVisitor::ExecuteTraversal(CSceneNode& current)
/*****************************************/
{
    AreWeOnWayUp(false);
    current.InjectVisitor(*this); //Inject on way down
    SceneNodeList children = current.Children();
    for(unsigned int c=0; c<children.size(); c++)
    {
        ExecuteTraversal(*children.at(c));
    }
    AreWeOnWayUp(true);
    current.InjectVisitor(*this); //Inject again on way back up
}

/*****************************************/
void CRenderVisitor::PerformOperation(CBoundAreaNode& node)
/*****************************************/
{
    if(!AreWeOnWayUp())
        BoundAreaStack().push(&node);
    else
        BoundAreaStack().pop();
}

/*****************************************/
void CRenderVisitor::PerformOperation(CDOFNode& node)
/*****************************************/
{
    if(!(AreWeOnWayUp()))
        node.ApplyTransformation();
    else
        node.UndoTransformation();
}

/*****************************************/
void CRenderVisitor::PerformOperation(CGeoNode& node)
/*****************************************/
{
    if(!AreWeOnWayUp())
    {
        if(node.OptionalBoundArea())
            BoundAreaStack().push(node.OptionalBoundArea());
        node.DrawMe();
    }
    else
    {
        if(node.OptionalBoundArea())
            BoundAreaStack().pop();
    }
}

/*****************************************/
void CRenderVisitor::PerformOperation(CMapSystemNode& node)
/*****************************************/
{
    if(!AreWeOnWayUp())
        MapSystemStack().push(&node);
    else
        MapSystemStack().pop();
}

/*****************************************/
void CRenderVisitor::PerformOperation(CProjectionNode& node)
/*****************************************/
{
    if(!AreWeOnWayUp())
        ProjectionStack().push(&node);
    else
        ProjectionStack().pop();

    CurrentProjection().ApplyProjection();
}

/*****************************************/
void CRenderVisitor::PerformOperation(CSceneNode& node)
/*****************************************/
{
    throw(CMochaException());
}

/*****************************************/
void CRenderVisitor::Run()
/*****************************************/
{
    if(!RootNode())
        return;

    CSceneNode& root = *(RootNode());
    ExecuteTraversal(root);
}



};
