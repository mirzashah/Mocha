/*****************************************************************************/
// Filename: DevicePoint.h
/*****************************************************************************/
/*****************************************************************************/

#ifndef DEVICE_POINT_H_DEFINED
#define DEVICE_POINT_H_DEFINED

namespace Mocha
{
class CDevicePoint
{

    public:
        CDevicePoint(int x = 0, int y = 0);
        ~CDevicePoint();

        bool operator == (const CDevicePoint& p) const;
        bool operator != (const CDevicePoint& p) const;

        int X() const;
        void X(int x);
        int Y() const;
        void Y(int y);

    private:
        int _x;
        int _y;
};

};

#endif
