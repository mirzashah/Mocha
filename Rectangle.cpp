#include <Rectangle.h>

namespace Mocha
{

/*******************************************/
CRectangle::CRectangle(double left, double right, double top, double bottom) :
_left(left),
_right(right),
_top(top),
_bottom(bottom)
/*******************************************/
{
}

#if 0
/*******************************************/
CRectangle::CRectangle(const CRectangle& rect)
/*******************************************/
{
    Left(rect.Left());
    Right(rect.Right());
    Top(rect.Top());
    Bottom(rect.Bottom());
}
#endif

/*******************************************/
CRectangle::~CRectangle()
/*******************************************/
{
}

/*******************************************/
double CRectangle::Left() const
/*******************************************/
{
    return(_left);
}

/*******************************************/
double CRectangle::Right() const
/*******************************************/
{
    return(_right);
}

/*******************************************/
double CRectangle::Top() const
/*******************************************/
{
    return(_top);
}

/*******************************************/
double CRectangle::Bottom() const
/*******************************************/
{
    return(_bottom);
}

/*******************************************/
void CRectangle::Left(double l)
/*******************************************/
{
    _left = l;
}

/*******************************************/
void CRectangle::Right(double r)
/*******************************************/
{
    _right = r;
}

/*******************************************/
void CRectangle::Top(double t)
/*******************************************/
{
    _top = t;
}

/*******************************************/
void CRectangle::Bottom(double b)
/*******************************************/
{
    _bottom = b;
}

};
