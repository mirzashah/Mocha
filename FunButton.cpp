#include <FunButton.h>
#include <Image.h>
#include <RectangleBoundAreaNode.h>

namespace Mocha
{

/*****************************************/
CFunButton::CFunButton(CImage* buttonImage, CDevicePoint buttonBottomLeft, EnterExitSide side) :
_boundArea(NULL),
_buttonBottomLeftPosition(buttonBottomLeft),
_buttonImage(NULL),
_entranceAndExit(side),
_isDismissed(false)
/*****************************************/
{
    ButtonImage(buttonImage);
    if(IsDismissed())
        CurrentPosition(DetermineExitPoint());
    else
        CurrentPosition(ToCartesian(ButtonBottomLeftPosition()));
    SetAnimationParameters();
}

/*****************************************/
CFunButton::~CFunButton()
/*****************************************/
{
}

/*****************************************/
void CFunButton::ButtonImage(CImage* image)
/*****************************************/
{
    _buttonImage = image;

    OptionalBoundArea(new CRectangleBoundAreaNode(0, Width(), Height(), 0));
}

/*****************************************/
CCartesianPoint CFunButton::DetermineExitPoint()
/*****************************************/
{
    int widthInPixels = ButtonImage()->WidthInPixels();
    int heightInPixels = ButtonImage()->HeightInPixels();
    CDevicePoint bottomLeftDev = ButtonBottomLeftPosition();
    switch(EntranceAndExit())
    {
        case EES_LEFT:
            return(ToCartesian(CDevicePoint(-widthInPixels, bottomLeftDev.Y())));
        case EES_RIGHT:
            return(ToCartesian(CDevicePoint(WindowWidth() + widthInPixels, bottomLeftDev.Y())));
        case EES_TOP:
            return(ToCartesian(CDevicePoint(bottomLeftDev.X(), WindowHeight()+heightInPixels)));
        case EES_BOTTOM:
            return(ToCartesian(CDevicePoint(bottomLeftDev.X(), -heightInPixels)));
        default:
            throw;
    };
}

/*****************************************/
void CFunButton::DrawMeFunny()
/*****************************************/
{
    glColor3f(1,1,1);
    ButtonImage()->DrawMe(ToCartesian(ButtonBottomLeftPosition()), IA_BOTTOMLEFT);
}

/*****************************************/
double CFunButton::Height()
/*****************************************/
{
    throw;
    //return(ButtonImage()->HeightInCartesian());
}

/*****************************************/
void CFunButton::OnUpdate()
/*****************************************/
{
    //Note: It's important that animation paremeters are only updated in on update. If we were
    //within a DrawMe, our modelview and projection will be messed up.
    SetAnimationParameters();
    CFunNode::OnUpdate();
}

/*****************************************/
void CFunButton::SetAnimationParameters()
/*****************************************/
{
    AnchorAngle(0);
    AnchorZoomFactor(1);
    RotationDelta(0);
    ZoomDelta(0);
    TranslateVelocity(0);

    if(IsDismissed())
    {
        AnchorPosition(DetermineExitPoint());
    }
    else
    {
        AnchorPosition(ToCartesian(ButtonBottomLeftPosition()));
    }
}

/*****************************************/
double CFunButton::Width()
/*****************************************/
{
    //return(ButtonImage()->WidthInCartesian());
    throw;
}

};
