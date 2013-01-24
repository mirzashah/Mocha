/*****************************************************************************/
// Filename: FunNode.h
/*****************************************************************************/
// Description: This node gives an easy way to do some fun animations.
/*****************************************************************************/

#ifndef MOCHA_FUN_NODE_H_DEFINED
#define MOCHA_FUN_NODE_H_DEFINED

#include <GeoNode.h>

namespace Mocha
{

class CFunNode : public CGeoNode
{
    public:
        CFunNode();
        virtual ~CFunNode();

        CCartesianPoint   AnchorPosition(){return(_anchorPosition);}
        void              AnchorPosition(const CCartesianPoint& p){_anchorPosition=p;}
        double            AnchorAngle(){return(_anchorAngle);}
        void              AnchorAngle(double angle){_anchorAngle = angle;}
        double            AnchorZoomFactor(){return(_anchorZoomFactor);}
        void              AnchorZoomFactor(double zoomFactor){_anchorZoomFactor=zoomFactor;}
        double            CurrentAngle(){return(_currentAngle);}
        void              CurrentAngle(double angle){_currentAngle = angle;}
        CCartesianPoint   CurrentPosition(){return(_currentPosition);}
        void              CurrentPosition(const CCartesianPoint& p){_currentPosition = p;}
        double            CurrentZoomFactor(){return(_currentZoomFactor);}
        void              CurrentZoomFactor(double zoomFactor){_currentZoomFactor = zoomFactor;}
        double            RotationDelta(){return(_rotationDelta);}
        void              RotationDelta(double delta){_rotationDelta = delta;}
        double            TranslateVelocity(){return(_translateVelocity);}
        void              TranslateVelocity(double v){_translateVelocity = v;}
        double            ZoomDelta(){return(_zoomDelta);}
        void              ZoomDelta(double delta){_zoomDelta = delta;}

        bool              IsAnchored();
        bool              WithinThreshold(double v1, double v2){return(fabs(v1-v2) <= 0.00001);}

    protected:
        virtual void      OnUpdate();
        virtual void      DrawMeFunny() = 0;

    private:
        virtual void      DrawMe();
        bool              IsAngleAnchored();
        bool              IsZoomFactorAnchored();
        bool              IsPositionAnchored();
        void              UpdateZoomFactor();
        void              UpdateAngle();
        void              UpdatePosition();

    private:
        double            _anchorAngle;
        CCartesianPoint   _anchorPosition;
        double            _anchorZoomFactor;

        double            _currentAngle;
        CCartesianPoint   _currentPosition;
        double            _currentZoomFactor;
        double            _rotationDelta;
        double            _translateVelocity;
        double            _zoomDelta;

};

};


#endif
