/*****************************************************************************/
// Filename: FunButton.h
/*****************************************************************************/
// Description: This class represents a simple button that utilizes the CFunNode's
// animation capabilities. The button when hovered over, does a slow zoom ala MacOS X,
// and when released, floats back down. The button can also be dismissed and fly off
// the screen, and can also fly back onto the screen when undismissed.
/*****************************************************************************/

#ifndef FUN_BUTTON_H_DEFINED
#define FUN_BUTTON_H_DEFINED

#include <FunNode.h>


namespace Mocha
{

enum EnterExitSide
{
    EES_LEFT,
    EES_RIGHT,
    EES_TOP,
    EES_BOTTOM
};

class CImage;
class CBoundAreaNode;
class CFunButton : public CFunNode
{
    public:
        CFunButton(CImage* buttonImage, CDevicePoint buttonBottomLeft, EnterExitSide side);
        virtual ~CFunButton();

        void              Comeback(){IsDismissed(false);}
        void              Dismiss(){IsDismissed(true);}

        CDevicePoint      ButtonBottomLeftPosition(){return(_buttonBottomLeftPosition);}
        void              ButtonBottomLeftPosition(CDevicePoint p){_buttonBottomLeftPosition = p;}

        double            Height();
        double            Width();

    protected:
        virtual void      DrawMeFunny();
        virtual void      OnUpdate();

    private:
        CBoundAreaNode*   BoundArea(){return(_boundArea);}
        void              BoundArea(CBoundAreaNode* boundArea){_boundArea = boundArea;}
        CImage*           ButtonImage(){return(_buttonImage);}
        void              ButtonImage(CImage* image);
        CCartesianPoint   DetermineExitPoint();
        EnterExitSide     EntranceAndExit() const {return(_entranceAndExit);}
        void              EntranceAndExit(EnterExitSide side){_entranceAndExit = side;}
        bool              IsDismissed(){return(_isDismissed);}
        void              IsDismissed(bool isIt){_isDismissed = isIt;}
        void              SetAnimationParameters();

    private:
        CDevicePoint      _buttonBottomLeftPosition;
        CBoundAreaNode*   _boundArea;
        CImage*           _buttonImage;
        EnterExitSide     _entranceAndExit;
        bool              _isDismissed;
};

};


#endif
