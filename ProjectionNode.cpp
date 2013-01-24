#include <ProjectionNode.h>
#include <GraphVisitor.h>
#include <MochaException.h>

namespace Mocha
{

/*********************************************/
CProjectionNode::CProjectionNode(double left, double right, double top, double bottom) :
_left(left),
_right(right),
_top(top),
_bottom(bottom)
/*********************************************/
{
}

/*********************************************/
CProjectionNode::~CProjectionNode()
/*********************************************/
{
}

/**********************************************/
void CProjectionNode::ApplyProjection()
/**********************************************/
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(Left(), Right(), Bottom(), Top());
}

/**********************************************/
void CProjectionNode::InjectVisitor(CGraphVisitor& visitor)
/**********************************************/
{
    visitor.PerformOperation(*this); //Double dispatch
}

/*********************************************/
double CProjectionNode::Bottom()
/*********************************************/
{
    return(_bottom);
}

/*********************************************/
void CProjectionNode::Bottom(double bottom)
/*********************************************/
{
    _bottom = bottom;
}

/*********************************************/
double CProjectionNode::Left()
/*********************************************/
{
    return(_left);
}

/*********************************************/
void CProjectionNode::Left(double left)
/*********************************************/
{
    _left = left;
}

/*********************************************/
double CProjectionNode::Right()
/*********************************************/
{
    return(_right);
}

/*********************************************/
void CProjectionNode::Right(double right)
/*********************************************/
{
    _right = right;
}

/*********************************************/
double CProjectionNode::Top()
/*********************************************/
{
    return(_top);
}

/*********************************************/
void CProjectionNode::Top(double top)
/*********************************************/
{
    _top = top;
}

};
