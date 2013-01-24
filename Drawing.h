/*****************************************************************************/
// Filename: Drawing.h
/*****************************************************************************/
// Description: This header contains a bunch of helper functions to aid in
// drawing. Users can implement their drawing code in OpenGL as well as use
// the calls provided in this file. The functions in the file use OpenGL
// primitives themselves to do drawing.
/*****************************************************************************/

#ifndef DRAWING_H_DEFINED
#define DRAWING_H_DEFINED

#include <MochaObject.h>

namespace Mocha
{

namespace Drawing
{

void  ArcXY(const CCartesianPoint& p, double radius, double startAngleInDegrees, double arcAngleInDegrees);
void  ArcXY(const CDevicePoint& p, double radius, double startAngleInDegrees, double arcAngleInDegrees);
void  ArcXY(const CGeographicalPoint& p, double radius, double startAngleInDegrees, double arcAngleInDegrees);
void  CircleDevice(const CDevicePoint& center, unsigned int radiusInPixels, bool fillWithBrush = false);
void  CircleDevice(const CCartesianPoint& center, unsigned int radiusInPixels, bool fillWithBrush = false);
void  CircleDevice(const CGeographicalPoint& center, unsigned int radiusInPixels, bool fillWithBrush = false);
void  CircleGeographical(const CDevicePoint& center, double radiusInUserSpace, bool fillWithBrush = false, bool useConstantAverageRadius = false);
void  CircleGeographical(const CGeographicalPoint& center, double radiusInUserSpace, bool fillWithBrush = false, bool useConstantAverageRadius = false);
void  CircleGeographical(const CCartesianPoint& center, double radiusInUserSpace, bool fillWithBrush = false,  bool useConstantAverageRadius = false);
void  CircleXY(const CDevicePoint& center, double radiusInUserSpace, bool fillWithBrush = false);
void  CircleXY(const CCartesianPoint& center, double radiusInUserSpace, bool fillWithBrush = false);
void  CircleXY(const CGeographicalPoint& center, double radiusInUserSpace, bool fillWithBrush = false) ;
void  ClosedCurve(DevicePointList& pointList, bool fillWithBrush = false);
void  ClosedCurve(CartesianPointList& xyPointList, bool fillWithBrush = false);
void  ClosedCurve(GeographicalPointList& latLongList, bool fillWithBrush = false);
void  EllipseDevice(const CDevicePoint& center, int widthInPixels, int heightInPixels, bool fillWithBrush = false);
void  EllipseDevice(const CCartesianPoint& center, int widthInPixels, int heightInPixels, bool fillWithBrush = false);
void  EllipseDevice(const CGeographicalPoint& center, int widthInPixels, int heightInPixels, bool fillWithBrush = false);
void  EllipseXY(const CDevicePoint& center, double widthInUserUnits, int heightInUserUnits, bool fillWithBrush = false);
void  EllipseXY(const CCartesianPoint& center, int widthInUserUnits, int heightInUserUnits, bool fillWithBrush = false);
void  EllipseXY(const CGeographicalPoint& center, int widthInUserUnits, int heightInUserUnits, bool fillWithBrush = false);
void  Line(const CDevicePoint& start, const CDevicePoint& end);
void  Line(const CDevicePoint& start, const CCartesianPoint& end);
void  Line(const CDevicePoint& start, const CGeographicalPoint& end);
void  Line(const CCartesianPoint& start, const CDevicePoint& end);
void  Line(const CCartesianPoint& start, const CCartesianPoint& end);
void  Line(const CCartesianPoint& start, const CGeographicalPoint& end);
void  Line(const CGeographicalPoint& start, const CDevicePoint& end);
void  Line(const CGeographicalPoint& start, const CCartesianPoint& end);
void  Line(const CGeographicalPoint& start, const CGeographicalPoint& end);
void  MultiPointGLPrimitive(const DevicePointList& pointList, GLenum mode);
void  MultiPointGLPrimitive(const CartesianPointList& pointList, GLenum mode);
void  MultiPointGLPrimitive(const GeographicalPointList& pointList, GLenum mode);
void  PieSlice(CDevicePoint topLeft, CDevicePoint bottomRight, double startAngleInDegrees, double sweepAngleInDegrees, bool fillWithBrush = false);
void  PieSlice(CCartesianPoint topLeft, CCartesianPoint bottomRight, double startAngleInDegrees, double sweepAngleInDegrees, bool fillWithBrush = false);
void  PieSlice(CGeographicalPoint topLeft, CGeographicalPoint bottomRight, double startAngleInDegrees, double sweepAngleInDegrees, bool fillWithBrush = false);
void  Polygon(const DevicePointList& pointList, bool fillWithBrush = false);
void  Polygon(const GeographicalPointList& pointList, bool fillWithBrush = false);
void  Polygon(const CartesianPointList& pointList, bool fillWithBrush = false);
void  Polyline(const DevicePointList& pointList);
void  Polyline(const CartesianPointList& xyPointList);
void  Polyline(const GeographicalPointList& latLongPointList);
void  RectangleDevice(CDevicePoint topLeft, int widthInPixels, int heightInPixels, bool fillWithBrush = false);
void  RectangleDevice(CGeographicalPoint topLeft, int widthInPixels, int heightInPixels, bool fillWithBrush = false);
void  RectangleDevice(CCartesianPoint topLeft, int widthInPixels, int heightInPixels, bool fillWithBrush = false);
void  RectangleXY(CDevicePoint topLeft, int widthInUserSpace, int heightInUserSpace, bool fillWithBrush = false);
void  RectangleXY(CGeographicalPoint topLeft, int widthInUserSpace, int heightInUserSpace, bool fillWithBrush = false);
void  RectangleXY(CCartesianPoint topLeft, int widthInUserSpace, int heightInUserSpace, bool fillWithBrush = false);

//Other
void  DisableAntiAliasing();
void  EnableAntiAliasing();
void  PenWidth(float width);

};

};

#endif
