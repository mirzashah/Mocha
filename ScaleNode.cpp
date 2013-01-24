#include <ScaleNode.h>

namespace Mocha
{

/***************************************/
CScaleNode::CScaleNode(double scaleX, double scaleY) :
_scaleX(scaleX),
_scaleY(scaleY)
/***************************************/
{
}

/***************************************/
CScaleNode::~CScaleNode()
/***************************************/
{
}

/***************************************/
void CScaleNode::ApplyTransformation()
/***************************************/
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScaled(ScaleX(), ScaleY(), 1);
}
/***************************************/
double CScaleNode::ScaleX() const
/***************************************/
{
    return(_scaleX);
}

/***************************************/
void CScaleNode::ScaleX(double scaleX)
/***************************************/
{
    _scaleX = scaleX;
}

/***************************************/
double CScaleNode::ScaleY() const
/***************************************/
{
    return(_scaleY);
}

/***************************************/
void CScaleNode::ScaleY(double scaleY)
/***************************************/
{
    _scaleY = scaleY;
}

/***************************************/
void CScaleNode::UndoTransformation()
/***************************************/
{
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

};
