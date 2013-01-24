#include <RectangleBoundAreaNode.h>

namespace Mocha
{

/*******************************************/
CRectangleBoundAreaNode::CRectangleBoundAreaNode(CRectangle rect) :
_rectangle(rect)
/*******************************************/
{
}

/*******************************************/
CRectangleBoundAreaNode::CRectangleBoundAreaNode(double left, double right, double top, double bottom) :
_rectangle(left, right, top, bottom)
/*******************************************/
{
}

/*******************************************/
CRectangleBoundAreaNode::~CRectangleBoundAreaNode()
/*******************************************/
{
}

/*******************************************/
bool CRectangleBoundAreaNode::IsMouseOverArea(CCartesianPoint mousePosition)
/*******************************************/
{
    return(mousePosition.X() > Left() && mousePosition.X() < Right() && mousePosition.Y() < Top() && mousePosition.Y() > Bottom());
}

/*******************************************/
double CRectangleBoundAreaNode::Left()
/*******************************************/
{
    return(Rectangle().Left());
}

/*******************************************/
double CRectangleBoundAreaNode::Right()
/*******************************************/
{
    return(Rectangle().Right());
}

/*******************************************/
double CRectangleBoundAreaNode::Top()
/*******************************************/
{
    return(Rectangle().Top());
}

/*******************************************/
double CRectangleBoundAreaNode::Bottom()
/*******************************************/
{
    return(Rectangle().Bottom());
}

/*******************************************/
void CRectangleBoundAreaNode::Left(double l)
/*******************************************/
{
    Rectangle().Left(l);
}

/*******************************************/
void CRectangleBoundAreaNode::Right(double r)
/*******************************************/
{
    Rectangle().Right(r);
}

/*******************************************/
void CRectangleBoundAreaNode::Top(double t)
/*******************************************/
{
    Rectangle().Top(t);
}

/*******************************************/
void CRectangleBoundAreaNode::Bottom(double b)
/*******************************************/
{
    Rectangle().Bottom(b);
}

};
