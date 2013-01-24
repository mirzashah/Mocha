#ifndef MOCHA_RECTANGLE_BOUND_AREA_NODE_H_DEFINED
#define MOCHA_RECTANGLE_BOUND_AREA_NODE_H_DEFINED

#include <BoundAreaNode.h>
#include <Rectangle.h>

namespace Mocha
{

class CRectangleBoundAreaNode : public CBoundAreaNode
{
    public:
        CRectangleBoundAreaNode(CRectangle rect);
        CRectangleBoundAreaNode(double left, double right, double top, double bottom);
        virtual ~CRectangleBoundAreaNode();
        double        Left();
        void          Left(double l);
        double        Right();
        void          Right(double r);
        double        Top();
        void          Top(double t);
        double        Bottom();
        void          Bottom(double b);

    protected:
        virtual bool IsMouseOverArea(CCartesianPoint mousePosition);

    private:
        CRectangle&  Rectangle(){return(_rectangle);}

    private:
        CRectangle  _rectangle;
};

};

#endif
