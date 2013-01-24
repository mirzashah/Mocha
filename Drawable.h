/*****************************************************************************/
// Filename: Drawable.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef MOCHA_DRAWABLE_H_DEFINED
#define MOCHA_DRAWABLE_H_DEFINED

#include <MochaObject.h>

namespace Mocha
{

class CDrawable : public CMochaObject
{
    public:
        CDrawable();
        virtual ~CDrawable();

    protected:
        double            CartesianToDeviceScaleXAxis();
        double            CartesianToDeviceScaleYAxis();
        CCartesianPoint   ToCartesian(const CDevicePoint& p);
        CCartesianPoint   ToCartesian(const CGeographicalPoint& p);
        CDevicePoint      ToDevice(const CCartesianPoint& p);
        CDevicePoint      ToDevice(const CGeographicalPoint& p);
        int               WindowHeight();
        int               WindowWidth();

};

};

#endif
