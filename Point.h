/*****************************************************************************/
// Filename: Point.h
/*****************************************************************************/
/*****************************************************************************/

#ifndef POINT_H_DEFINED
#define POINT_H_DEFINED

#include <MapSystemCore.h>
#include <DevicePoint.h>
#include <list>
using std::list;

namespace Mocha
{
    typedef CXYPoint                   CCartesianPoint;
    typedef CLatLongPoint              CGeographicalPoint;
    typedef list<CDevicePoint>         DevicePointList;
    typedef list<CCartesianPoint>      CartesianPointList;
    typedef list<CGeographicalPoint>   GeographicalPointList;
};

#endif
