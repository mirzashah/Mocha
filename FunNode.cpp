#include <FunNode.h>

namespace Mocha
{

/*****************************************/
CFunNode::CFunNode()
/*****************************************/
{
    AnchorPosition(CCartesianPoint(0,0));
    AnchorAngle(0);
    AnchorZoomFactor(1);
    CurrentAngle(0);
    CurrentPosition(CCartesianPoint(0,0));
    CurrentZoomFactor(1);
    RotationDelta(0);
    TranslateVelocity(0);
    ZoomDelta(0);
}

/*****************************************/
CFunNode::~CFunNode()
/*****************************************/
{
}

/*****************************************/
void CFunNode::DrawMe()
/*****************************************/
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScaled(CurrentZoomFactor(), CurrentZoomFactor(), 1);
    glRotated(CurrentAngle(), 0, 0, 1);
    glTranslated(CurrentPosition().X(), CurrentPosition().Y(), 0);

    DrawMeFunny();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

/*****************************************/
bool CFunNode::IsAnchored()
/*****************************************/
{
    return(IsAngleAnchored()&&IsZoomFactorAnchored()&&IsPositionAnchored());
}

/*****************************************/
bool CFunNode::IsAngleAnchored()
/*****************************************/
{
    return(WithinThreshold(AnchorAngle(),CurrentAngle()));
}

/*****************************************/
bool CFunNode::IsZoomFactorAnchored()
/*****************************************/
{
    return(WithinThreshold(AnchorZoomFactor(),CurrentZoomFactor()));
}

/*****************************************/
bool CFunNode::IsPositionAnchored()
/*****************************************/
{
    bool isXGood = WithinThreshold(AnchorPosition().X(),CurrentPosition().X());
    bool isYGood = WithinThreshold(AnchorPosition().Y(),CurrentPosition().Y());
    return(isXGood && isYGood);
}

/*****************************************/
void CFunNode::OnUpdate()
/*****************************************/
{
    if(!IsAnchored())
        InvalidateScene();

    if(!IsZoomFactorAnchored())
        UpdateZoomFactor();
    if(!IsAngleAnchored())
        UpdateAngle();
    if(!IsPositionAnchored())
        UpdatePosition();
}

/*****************************************/
void CFunNode::UpdateZoomFactor()
/*****************************************/
{
    CurrentZoomFactor(CurrentZoomFactor() + ZoomDelta());
}

/*****************************************/
void CFunNode::UpdateAngle()
/*****************************************/
{
    CurrentAngle(CurrentAngle() + RotationDelta());
}

/*****************************************/
void CFunNode::UpdatePosition()
/*****************************************/
{
    double v = fabs(TranslateVelocity());
    CCartesianPoint pos = CurrentPosition();
    CCartesianPoint posDest = AnchorPosition();
    double deltaX = 0;
    double deltaY = 0;
    if(pos.X() < posDest.X())
        deltaX = v;
    else
        deltaX = -(v);

    if(pos.Y() < posDest.Y())
        deltaY = v;
    else
        deltaY = -(v);

    CurrentPosition(CCartesianPoint(pos.X()+deltaX, pos.Y()+deltaY));
}

};
