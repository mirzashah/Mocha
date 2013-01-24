#include <Drawable.h>
#include <SceneManager.h>

namespace Mocha
{

/***************************************/
CDrawable::CDrawable()
/***************************************/
{
}

/***************************************/
CDrawable::~CDrawable()
/***************************************/
{
}

/*********************************************/
double CDrawable::CartesianToDeviceScaleXAxis()
/*********************************************/
{
    return(CurrentSceneManager()->CartesianToDeviceScaleXAxis());
}

/*********************************************/
double CDrawable::CartesianToDeviceScaleYAxis()
/*********************************************/
{
    return(CurrentSceneManager()->CartesianToDeviceScaleYAxis());
}

/*********************************************/
CCartesianPoint CDrawable::ToCartesian(const CDevicePoint& p)
/*********************************************/
{
    return(CurrentSceneManager()->ToCartesian(p));
}

/*********************************************/
CCartesianPoint CDrawable::ToCartesian(const CGeographicalPoint& p)
/*********************************************/
{
    return(CurrentSceneManager()->ToCartesian(p));
}

/*********************************************/
CDevicePoint CDrawable::ToDevice(const CCartesianPoint& p)
/*********************************************/
{
    return(CurrentSceneManager()->ToDevice(p));
}

/*********************************************/
CDevicePoint CDrawable::ToDevice(const CGeographicalPoint& p)
/*********************************************/
{
    return(CurrentSceneManager()->ToDevice(p));
}

/*********************************************/
int CDrawable::WindowWidth()
/*********************************************/
{
    return(CurrentSceneManager()->WindowWidth());
}

/*********************************************/
int CDrawable::WindowHeight()
/*********************************************/
{
    return(CurrentSceneManager()->WindowHeight());
}
};
