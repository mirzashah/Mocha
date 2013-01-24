/*****************************************************************************/
// Filename: RenderVisitor.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef RENDER_VISITOR_H_DEFINED
#define RENDER_VISITOR_H_DEFINED

#include <GraphVisitor.h>

namespace Mocha
{

class CRenderVisitor: public CGraphVisitor
{
    public:
        CRenderVisitor(CSceneNode* rootNode);
        virtual ~CRenderVisitor();

        virtual void Run();

    private:
        bool         AreWeOnWayUp();
        void         AreWeOnWayUp(bool areWe);
        void         ExecuteTraversal(CSceneNode& current);
        virtual void PerformOperation(CBoundAreaNode& node);
        virtual void PerformOperation(CDOFNode& node);
        virtual void PerformOperation(CGeoNode& node);
        virtual void PerformOperation(CMapSystemNode& node);
        virtual void PerformOperation(CProjectionNode& node);
        virtual void PerformOperation(CSceneNode& node);

    private:
        bool         _areWeOnWayUp;

};

};

#endif
