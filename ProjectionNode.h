#ifndef PROJECTION_NODE_H_DEFINED
#define PROJECTION_NODE_H_DEFINED

#include <SceneNode.h>

namespace Mocha
{
class CProjectionNode: public CSceneNode
{
    friend class CEventVisitor;
    friend class CRenderVisitor;
    friend class CUpdateVisitor;
    friend class CSceneManager;

    public:
        CProjectionNode(double left, double right, double top, double bottom);
        virtual ~CProjectionNode();

    public:
        double        Left();
        void          Left(double left);
        double        Right();
        void          Right(double right);
        double        Top();
        void          Top(double top);
        double        Bottom();
        void          Bottom(double bottom);

    protected:
        void          ApplyProjection();

    protected:
        virtual void  InjectVisitor(CGraphVisitor& visitor);

    private:
        double        _left;
        double        _right;
        double        _top;
        double        _bottom;
};
};

#endif
