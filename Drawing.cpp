#include <Drawing.h>
#include <SceneManager.h>
#include <iostream>
using namespace std;

namespace Mocha
{
namespace Drawing
{

/*******************************************************/
static CSceneManager*               CurrentSceneManager(){return(CMochaObject().CurrentSceneManager());}
static int                          GetNumberOfCircleSegments(double radius);
static double                       CartesianToDeviceScaleXAxis()                     {return(CurrentSceneManager()->CartesianToDeviceScaleXAxis());}
static double                       CartesianToDeviceScaleYAxis()                     {return(CurrentSceneManager()->CartesianToDeviceScaleYAxis());}
//static double                       DeviceToCartesianScaleXAxis()                     {return(1/CartesianToDeviceScaleXAxis());}
//static double                       DeviceToCartesianScaleYAxis()                     {return(1/CartesianToDeviceScaleYAxis());}
static CCartesianPoint              ToCartesian(const CDevicePoint& p)                {return(CurrentSceneManager()->ToCartesian(p));}
static CCartesianPoint              ToCartesian(const CGeographicalPoint& p)          {return(CurrentSceneManager()->ToCartesian(p));}
static CartesianPointList           ToCartesian(const DevicePointList& points)        {return(CurrentSceneManager()->ToCartesian(points));}
static CartesianPointList           ToCartesian(const GeographicalPointList& points)  {return(CurrentSceneManager()->ToCartesian(points));}
//static CDevicePoint                 ToDevice(const CCartesianPoint& p)                {return(CurrentSceneManager()->ToDevice(p));}
//static CDevicePoint                 ToDevice(const CGeographicalPoint& p)             {return(CurrentSceneManager()->ToDevice(p));}
//static DevicePointList              ToDevice(const CartesianPointList& points)        {return(CurrentSceneManager()->ToDevice(points));}
//static DevicePointList              ToDevice(const GeographicalPointList& points)     {return(CurrentSceneManager()->ToDevice(points));}
//static CGeographicalPoint           ToGeographical(const CCartesianPoint& p)          {return(CurrentSceneManager()->ToGeographical(p));}
//static CGeographicalPoint           ToGeographical(const CDevicePoint& p)             {return(CurrentSceneManager()->ToGeographical(p));}
//static GeographicalPointList        ToGeographical(const CartesianPointList& points)  {return(CurrentSceneManager()->ToGeographical(points));}
//static GeographicalPointList        ToGeographical(const DevicePointList& points)     {return(CurrentSceneManager()->ToGeographical(points));}
/*******************************************************/

/*******************************************************/
void ArcXY(const CCartesianPoint& p, double radius, double startAngleInDegrees, double arcAngleInDegrees)
/*******************************************************/
{
    double cx           = p.X();
    double cy           = p.Y();
    double numSegments  = GetNumberOfCircleSegments(radius);
    double startAngle   = toRad(startAngleInDegrees);
    double arcAngle     = toRad(arcAngleInDegrees);

	double theta = arcAngle / double(numSegments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	double tangetial_factor = tan(theta);

	double radial_factor = cos(theta);


	double x = radius * cos(startAngle);//we now start at the start angle
	double y = radius * sin(startAngle);

	glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
	for(int ii = 0; ii < numSegments; ii++)
	{
		glVertex2d(x + cx, y + cy);

		double tx = -y;
		double ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
}

/*******************************************************/
void ArcXY(const CDevicePoint& p, double radius, double startAngleInDegrees, double arcAngleInDegrees)
/*******************************************************/
{
    ArcXY(ToCartesian(p), radius, startAngleInDegrees, arcAngleInDegrees);
}

/*******************************************************/
void ArcXY(const CGeographicalPoint& p, double radius, double startAngleInDegrees, double arcAngleInDegrees)
/*******************************************************/
{
    ArcXY(ToCartesian(p), radius, startAngleInDegrees, arcAngleInDegrees);
}

/*******************************************************/
CartesianPointList GenerateCartesianSpaceCirclePoints(const CCartesianPoint& p, double radius)
/*******************************************************/
{
    CartesianPointList toReturn;
    double cx = p.X();
    double cy = p.Y();
    double numSegments = GetNumberOfCircleSegments(radius);
	double theta = 2 * 3.1415926 / float(numSegments);
	double tangetial_factor = tan(theta);//calculate the tangential factor

	double radial_factor = cos(theta);//calculate the radial factor

	double x = radius;//we start at angle = 0
	double y = 0;

	for(int ii = 0; ii < numSegments; ii++)
	{
	    toReturn.push_back(CCartesianPoint(x+cx, y+cy));
		//calculate the tangential vector
		//remember, the radial vector is (x, y)
		//to get the tangential vector we flip those coordinates and negate one of them

		double tx = -y;
		double ty = x;

		//add the tangential vector

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		//correct using the radial factor

		x *= radial_factor;
		y *= radial_factor;
	}
    return(toReturn);
}

/*******************************************************/
CartesianPointList GenerateDeviceSpaceCirclePoints(const CCartesianPoint& p, unsigned int radiusInPixels)
/*******************************************************/
{
    CartesianPointList toReturn;
    double cx = p.X();
    double cy = p.Y();
    const double scaleCartToDevX = CartesianToDeviceScaleXAxis();
    const double scaleCartToDevY = CartesianToDeviceScaleYAxis();

    double numSegments = GetNumberOfCircleSegments(radiusInPixels); //MAS - The algorithm seems to be ok except this part. Not sure the math behind how segments calculated.
    cout<<"Number of device segments: "<<numSegments<<endl;
	double theta = 2 * 3.1415926 / float(numSegments);
	double tangetial_factor = tan(theta);//calculate the tangential factor

	double radial_factor = cos(theta);//calculate the radial factor

	double x = radiusInPixels;//we start at angle = 0
	double y = 0;

	for(int ii = 0; ii < numSegments; ii++)
	{
	    toReturn.push_back(CCartesianPoint((x*scaleCartToDevX)+cx, (y*scaleCartToDevY)+cy));
		//calculate the tangential vector
		//remember, the radial vector is (x, y)
		//to get the tangential vector we flip those coordinates and negate one of them

		double tx = -y;
		double ty = x;

		//add the tangential vector

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		//correct using the radial factor

		x *= radial_factor;
		y *= radial_factor;
	}
    return(toReturn);
}

/*******************************************************/
void  CircleDevice(const CDevicePoint& center, unsigned int radiusInPixels, bool fillWithBrush)
/*******************************************************/
{
    CircleDevice(ToCartesian(center), radiusInPixels, fillWithBrush);
}

/*******************************************************/
void  CircleDevice(const CCartesianPoint& center, unsigned int radiusInPixels, bool fillWithBrush)
/*******************************************************/
{
    MultiPointGLPrimitive(GenerateDeviceSpaceCirclePoints(center, radiusInPixels), (fillWithBrush ? GL_POLYGON : GL_LINE_LOOP));
}

/*******************************************************/
void  CircleDevice(const CGeographicalPoint& center, unsigned int radiusInPixels, bool fillWithBrush)
/*******************************************************/
{
    CircleDevice(ToCartesian(center), radiusInPixels, fillWithBrush);
}

/*******************************************************/
int GetNumberOfCircleSegments(double radius)
/*******************************************************/
{
	return int(2.0f * 3.1415926f / (acos(1.0f - 0.25f / radius)));//change the 0.25 to a smaller/bigger number as needed
}

/*******************************************************/
void  CircleGeographical(const CDevicePoint& center, double radiusInUserSpace, bool fillWithBrush, bool useConstantAverageRadius)
/*******************************************************/
{
}

/*******************************************************/
void  CircleGeographical(const CGeographicalPoint& center, double radiusInUserSpace, bool fillWithBrush, bool useConstantAverageRadius)
/*******************************************************/
{
}

/*******************************************************/
void  CircleGeographical(const CCartesianPoint& center, double radiusInUserSpace, bool fillWithBrush,  bool useConstantAverageRadius)
/*******************************************************/
{
}

/*******************************************************/
void CircleXY(const CCartesianPoint& p, double radius, bool fillWithBrush)
/*******************************************************/
{
    MultiPointGLPrimitive(GenerateCartesianSpaceCirclePoints(p, radius), (fillWithBrush ? GL_POLYGON : GL_LINE_LOOP));
}

/*******************************************************/
void CircleXY(const CDevicePoint& p, double radius, bool fillWithBrush)
/*******************************************************/
{
    CircleXY(ToCartesian(p), radius, fillWithBrush);
}

/*******************************************************/
void CircleXY(const CGeographicalPoint& p, double radius, bool fillWithBrush)
/*******************************************************/
{
    CircleXY(ToCartesian(p), radius, fillWithBrush);
}

/*******************************************************/
void  ClosedCurve(DevicePointList& pointList, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  ClosedCurve(CartesianPointList& xyPointList, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  ClosedCurve(GeographicalPointList& latLongList, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  EllipseDevice(CDevicePoint center, int widthInPixels, int heightInPixels, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  EllipseDevice(CCartesianPoint center, int widthInPixels, int heightInPixels, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  EllipseDevice(CGeographicalPoint center, int widthInPixels, int heightInPixels, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  EllipseXY(CDevicePoint center, double widthInUserUnits, int heightInUserUnits, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  EllipseXY(CCartesianPoint center, int widthInUserUnits, int heightInUserUnits, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  EllipseXY(CGeographicalPoint center, int widthInUserUnits, int heightInUserUnits, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  DisableAntiAliasing()
/*******************************************************/
{
    glDisable(GL_LINE_SMOOTH);
}

/*******************************************************/
void  EnableAntiAliasing()
/*******************************************************/
{
    glEnable(GL_LINE_SMOOTH);
}

/*******************************************************/
void  Line(const CDevicePoint& start, const CDevicePoint& end)
/*******************************************************/
{
    Line(ToCartesian(start), ToCartesian(end));
}

/*******************************************************/
void  Line(const CDevicePoint& start, const CCartesianPoint& end)
/*******************************************************/
{
    Line(ToCartesian(start), end);
}

/*******************************************************/
void  Line(const CDevicePoint& start, const CGeographicalPoint& end)
/*******************************************************/
{
    Line(ToCartesian(start), ToCartesian(end));
}

/*******************************************************/
void  Line(const CCartesianPoint& start, const CDevicePoint& end)
/*******************************************************/
{
    Line(start, ToCartesian(end));
}

/*******************************************************/
void Line(const CCartesianPoint& p1, const CCartesianPoint& p2)
/*******************************************************/
{
    glBegin(GL_LINES);
        glVertex2d(p1.X(), p1.Y());
        glVertex2d(p2.X(), p2.Y());
    glEnd();
}

/*******************************************************/
void  Line(const CCartesianPoint& start, const CGeographicalPoint& end)
/*******************************************************/
{
    Line(start, ToCartesian(end));
}

/*******************************************************/
void  Line(const CGeographicalPoint& start, const CDevicePoint& end)
/*******************************************************/
{
    Line(ToCartesian(start), ToCartesian(end));
}

/*******************************************************/
void  Line(const CGeographicalPoint& start, const CCartesianPoint& end)
/*******************************************************/
{
    Line(ToCartesian(start), end);
}

/*******************************************************/
void  Line(const CGeographicalPoint& start, const CGeographicalPoint& end)
/*******************************************************/
{
    Line(ToCartesian(start), ToCartesian(end));
}

/*******************************************************/
void MultiPointGLPrimitive(const DevicePointList& pointList, GLenum mode)
/*******************************************************/
{
    CartesianPointList pointListXY = ToCartesian(pointList);
    MultiPointGLPrimitive(pointListXY, mode);
}

/*******************************************************/
void MultiPointGLPrimitive(const CartesianPointList& pointList, GLenum mode)
/*******************************************************/
{
    glBegin(mode);
        for(CartesianPointList::const_iterator itr=pointList.begin(); itr!=pointList.end(); itr++)
            glVertex2d(itr->X(), itr->Y());
    glEnd();
}

/*******************************************************/
void MultiPointGLPrimitive(const GeographicalPointList& pointList, GLenum mode)
/*******************************************************/
{
    MultiPointGLPrimitive(ToCartesian(pointList), mode);
}

/*******************************************************/
void PenWidth(float width)
/*******************************************************/
{
    glLineWidth(width);
}

/*******************************************************/
void  PieSlice(CDevicePoint topLeft, CDevicePoint bottomRight, double startAngleInDegrees, double sweepAngleInDegrees)
/*******************************************************/
{
}

/*******************************************************/
void  PieSlice(CCartesianPoint topLeft, CCartesianPoint bottomRight, double startAngleInDegrees, double sweepAngleInDegrees, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  PieSlice(CGeographicalPoint topLeft, CGeographicalPoint bottomRight, double startAngleInDegrees, double sweepAngleInDegrees, bool fillWithBrush)
/*******************************************************/
{
}

/*******************************************************/
void  Polygon(const DevicePointList& pointList, bool fillWithBrush)
/*******************************************************/
{
    Polygon(ToCartesian(pointList));
}

/*******************************************************/
void  Polygon(const GeographicalPointList& pointList, bool fillWithBrush)
/*******************************************************/
{
    Polygon(ToCartesian(pointList), fillWithBrush);
}

/*******************************************************/
void  Polygon(const CartesianPointList& pointList, bool fillWithBrush)
/*******************************************************/
{
    MultiPointGLPrimitive(pointList, (fillWithBrush ? GL_POLYGON : GL_LINE_LOOP));
}

/*******************************************************/
void Polyline(const DevicePointList& pointList)
/*******************************************************/
{
    Polyline(ToCartesian(pointList));
}

/*******************************************************/
void  Polyline(const CartesianPointList& xyPointList)
/*******************************************************/
{
    MultiPointGLPrimitive(xyPointList, GL_LINES);
}

/*******************************************************/
void  Polyline(const GeographicalPointList& latLongPointList)
/*******************************************************/
{
    Polyline(ToCartesian(latLongPointList));
}

/*******************************************************/
void  RectangleDevice(CDevicePoint topLeft, int widthInPixels, int heightInPixels, bool fillWithBrush)
/*******************************************************/
{
    RectangleDevice(ToCartesian(topLeft), widthInPixels, heightInPixels, fillWithBrush);
}

/*******************************************************/
void RectangleDevice(CGeographicalPoint topLeft, int widthInPixels, int heightInPixels, bool fillWithBrush)
/*******************************************************/
{
    RectangleDevice(ToCartesian(topLeft), widthInPixels, heightInPixels, fillWithBrush);
}

/*******************************************************/
void RectangleDevice(CCartesianPoint topLeft, int widthInPixels, int heightInPixels, bool fillWithBrush)
/*******************************************************/
{
    RectangleXY(topLeft, widthInPixels * CartesianToDeviceScaleXAxis(), heightInPixels * CartesianToDeviceScaleYAxis(), fillWithBrush);
}

/*******************************************************/
void RectangleXY(CDevicePoint topLeft, int widthInUserSpace, int heightInUserSpace, bool fillWithBrush)
/*******************************************************/
{
    RectangleXY(ToCartesian(topLeft), widthInUserSpace, heightInUserSpace, fillWithBrush);
}

/*******************************************************/
void RectangleXY(CGeographicalPoint topLeft, int widthInUserSpace, int heightInUserSpace, bool fillWithBrush)
/*******************************************************/
{
    RectangleXY(ToCartesian(topLeft), widthInUserSpace, heightInUserSpace, fillWithBrush);
}

/*******************************************************/
void  RectangleXY(CCartesianPoint topLeft, int widthInUserSpace, int heightInUserSpace, bool fillWithBrush)
/*******************************************************/
{
    double xLeft   = topLeft.X();
    double xRight  = xLeft + widthInUserSpace;
    double yTop    = topLeft.Y();
    double yBottom = yTop - heightInUserSpace;

    CartesianPointList points;
    points.push_back(topLeft);
    points.push_back(CCartesianPoint(xRight, yTop));
    points.push_back(CCartesianPoint(xRight, yBottom));
    points.push_back(CCartesianPoint(xLeft, yBottom));

    MultiPointGLPrimitive(points, (fillWithBrush ? GL_POLYGON : GL_LINE_LOOP));
}

};
};
