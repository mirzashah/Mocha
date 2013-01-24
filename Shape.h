/*****************************************************************************/
// Filename: Shape.h
/*****************************************************************************/
// Description: Represents a generic shape.
/*****************************************************************************/

#ifndef MOCHA_SHAPE_H_DEFINED
#define MOCHA_SHAPE_H_DEFINED

#include <MochaObject.h>

namespace Mocha
{

class CShape : public CMochaObject
{
    public:
        CShape();
        virtual ~CShape();

        //TODO: I want to have a shape be able to produce its corresponding points so that I can create
        //a get rid of the Drawable functions and just have a class for drawing shapes that dervies from
        //CDrawable (e.g. CShapeDrawer)
        //virtual pair<glDoublev, int> GetAsSeriesOfPoints();

};

};


#endif
