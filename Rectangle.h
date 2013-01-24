/*****************************************************************************/
// Filename: Rectangle.h
/*****************************************************************************/
// Description: Represents a generic rectangle
/*****************************************************************************/

#ifndef MOCHA_RECTANGLE_H_DEFINED
#define MOCHA_RECTANGLE_H_DEFINED

#include <Shape.h>

namespace Mocha
{

class CRectangle : public CShape
{

    public:
        CRectangle(double left, double right, double top, double bottom);
        //CRectangle(const CRectangle& rect);
        virtual ~CRectangle();

        double       Left() const;
        void         Left(double l);
        double       Right() const;
        void         Right(double r);
        double       Top() const;
        void         Top(double t);
        double       Bottom() const;
        void         Bottom(double b);

    private:
        double      _left;
        double      _right;
        double      _top;
        double      _bottom;


};

};



#endif
