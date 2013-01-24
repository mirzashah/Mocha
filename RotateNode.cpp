#include <RotateNode.h>

namespace Mocha
{

/***************************************/
CRotateNode::CRotateNode(double angleInDegrees, double rotateAxisX, double rotateAxisY) :
_angleInDegrees(angleInDegrees),
_rotateAxisX(rotateAxisX),
_rotateAxisY(rotateAxisY)
/***************************************/
{
}

/***************************************/
CRotateNode::~CRotateNode()
/***************************************/
{
}

/***************************************/
void CRotateNode::ApplyTransformation()
/***************************************/
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(AngleInDegrees(), RotateAxisX(), RotateAxisY(), 0);
}

/***************************************/
double CRotateNode::AngleInDegrees() const
/***************************************/
{
    return(_angleInDegrees);
}

/***************************************/
void CRotateNode::AngleInDegrees(double deg)
/***************************************/
{
    _angleInDegrees = deg;
}

/***************************************/
double CRotateNode::RotateAxisX() const
/***************************************/
{
    return(_rotateAxisX);
}

/***************************************/
void CRotateNode::RotateAxisX(double deg)
/***************************************/
{
    _rotateAxisX = deg;
}

/***************************************/
double CRotateNode::RotateAxisY() const
/***************************************/
{
    return(_rotateAxisY);
}

/***************************************/
void CRotateNode::RotateAxisY(double deg)
/***************************************/
{
    _rotateAxisY = deg;
}

/***************************************/
void CRotateNode::UndoTransformation()
/***************************************/
{
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

};
