#include "PolygonTessalator.h"

namespace Mocha
{

/********************************************************/
CPolygonTessalator::CPolygonTessalator()
/********************************************************/
{
}

/********************************************************/
CPolygonTessalator::~CPolygonTessalator()
/********************************************************/
{
}

/********************************************************/
void CPolygonTessalator::DrawConcavePolygon(GLdouble** polygonAs3by1MatrixList, int n)
/********************************************************/
{
//    GLuint id = glGenLists(1);  // create a display list
//    if(!id) return id;          // failed to create a list, return 0

    GLUtesselator *tess = gluNewTess(); // create a tessellator
    //if(!tess) return 0;  // failed to create tessellation object, return 0
    if(!tess) throw;
    // define concave quad data (vertices only)
    //  0    2
    //  \ \/ /
    //   \3 /
    //    \/
    //    1
    //GLdouble quad1[4][3] = { {-1,3,0}, {0,0,0}, {1,3,0}, {0,2,0} };

    // register callback functions
    gluTessCallback(tess, GLU_TESS_BEGIN, (void (CALLBACK *)())tessBeginCB);
    gluTessCallback(tess, GLU_TESS_END, (void (CALLBACK *)())tessEndCB);
    gluTessCallback(tess, GLU_TESS_ERROR, (void (CALLBACK *)())tessErrorCB);
    gluTessCallback(tess, GLU_TESS_VERTEX, (void (CALLBACK *)())tessVertexCB);

    // tessellate and compile a concave quad into display list
    // gluTessVertex() takes 3 params: tess object, pointer to vertex coords,
    // and pointer to vertex data to be passed to vertex callback.
    // The second param is used only to perform tessellation, and the third
    // param is the actual vertex data to draw. It is usually same as the second
    // param, but It can be more than vertex coord, for example, color, normal
    // and UV coords which are needed for actual drawing.
    // Here, we are looking at only vertex coods, so the 2nd and 3rd params are
    // pointing same address.
    //glNewList(id, GL_COMPILE);
    glColor3f(1,1,1);
    gluTessBeginPolygon(tess, 0);                   // with NULL data
        gluTessBeginContour(tess);
//            gluTessVertex(tess, quad1[0], quad1[0]);
//            gluTessVertex(tess, quad1[1], quad1[1]);
//            gluTessVertex(tess, quad1[2], quad1[2]);
//            gluTessVertex(tess, quad1[3], quad1[3]);
        for(unsigned int c=0; c<n; c++)
            gluTessVertex(tess, polygonAs3by1MatrixList[c], polygonAs3by1MatrixList[c]);
        gluTessEndContour(tess);
    gluTessEndPolygon(tess);
    glEndList();

    gluDeleteTess(tess);        // delete after tessellation

//    return id;      // return handle ID of a display list
}

};