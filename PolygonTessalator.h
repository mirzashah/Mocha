#ifndef POLYGON_TESSALATOR_H_DEFINED
#define POLYGON_TESSALATOR_H_DEFINED

#include <MochaObject.h>

namespace Mocha
{

class CPolygonTessalator : public CMochaObject
{
    public:
        CPolygonTessalator();
        virtual ~CPolygonTessalator();

        void DrawConcavePolygon(GLdouble** polygonAs3by1MatrixList, int n);

    private:
        static void CALLBACK tessBeginCB(GLenum which);
        static void CALLBACK tessEndCB();
        static void CALLBACK tessErrorCB(GLenum errorCode);
        static void CALLBACK tessVertexCB(const GLvoid *data);
        static void CALLBACK tessVertexCB2(const GLvoid *data);
        static void CALLBACK tessCombineCB(const GLdouble newVertex[3], const GLdouble *neighborVertex[4],
                                    const GLfloat neighborWeight[4], GLdouble **outData);

};

};



#endif