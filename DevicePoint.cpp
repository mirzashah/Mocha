#include <DevicePoint.h>

namespace Mocha
{

/*******************************************/
CDevicePoint::CDevicePoint(int x, int y) :
_x(x),
_y(y)
/*******************************************/
{
}

/*******************************************/
CDevicePoint::~CDevicePoint()
/*******************************************/
{
}

/**************************************************/
bool CDevicePoint::operator == (const CDevicePoint& p) const
/**************************************************/
{
    return (p.X()==X() && p.Y()==Y());
}

/**************************************************/
bool CDevicePoint::operator != (const CDevicePoint& p) const
/**************************************************/
{
    return (!((*this)==p));
}

/*******************************************/
int CDevicePoint::X() const
/*******************************************/
{
    return(_x);
}

/*******************************************/
void CDevicePoint::X(int x)
/*******************************************/
{
    _x = x;
}

/*******************************************/
int CDevicePoint::Y() const
/*******************************************/
{
    return(_y);
}

/*******************************************/
void CDevicePoint::Y(int y)
/*******************************************/
{
    _y = y;
}

};