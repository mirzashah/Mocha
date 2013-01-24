/*****************************************************************************/
// Filename: Circle.h
/*****************************************************************************/
// Description: Represents a generic circle
/*****************************************************************************/

#ifndef MOCHA_CIRCLE_H_DEFINED
#define MOCHA_CIRCLE_H_DEFINED

#include <Shape.h>

namespace Mocha
{

template <typename T> class CCircle : public CShape
{

    public:
        CCircle(T center, double radius) : _center(center), _radius(radius)
        {
        }

        virtual ~CCircle();

        T Center()
        {
            return(_center);
        }
        void Center(const T& center)
        {
            _center = center;
        }

        double Radius()
        {
            return(_radius);
        }

        void Radius(double radius)
        {
            _radius = radius;
        }

    private:
        void GarbageFunction() //Note: Garbage function ensures that T has an X and Y method ;)
        {
            Center().X();
            Center().Y();
        };

    private:
        T      _center;
        double _radius;
};

};



#endif

