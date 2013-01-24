#include <TranslateNode.h>

namespace Mocha
{

/***************************************/
CTranslateNode::CTranslateNode(double translateX, double translateY)
/***************************************/
{
}

/***************************************/
CTranslateNode::~CTranslateNode()
/***************************************/
{
}

/***************************************/
void CTranslateNode::ApplyTransformation()
/***************************************/
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(TranslateX(), TranslateY(), 0);
}

/***************************************/
double CTranslateNode::TranslateX() const
/***************************************/
{
    return(_translateX);
}

/***************************************/
void CTranslateNode::TranslateX(double translateX)
/***************************************/
{
    _translateX = translateX;
}

/***************************************/
double CTranslateNode::TranslateY() const
/***************************************/
{
    return(_translateY);
}

/***************************************/
void CTranslateNode::TranslateY(double translateY)
/***************************************/
{
    _translateY = translateY;
}

/***************************************/
void CTranslateNode::UndoTransformation()
/***************************************/
{
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

};
