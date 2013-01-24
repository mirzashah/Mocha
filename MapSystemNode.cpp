#include <MapSystemNode.h>
#include <GraphVisitor.h>
#include <MochaException.h>

namespace Mocha
{

/**********************************************/
CMapSystemNode::CMapSystemNode(WORLD_MODEL_TYPE referenceEllipsoidType, PROJECTED_MODEL_TYPE projectionType, CGeographicalPoint projectionCenter) :
_referenceEllipsoidType(referenceEllipsoidType),
_projectionType(projectionType),
_projectionCenter(projectionCenter),
_projection(NULL),
_referenceEllipsoid(NULL)
/**********************************************/
{
    UpdateProjection();
    UpdateReferenceEllipsoid();
}

/**********************************************/
CMapSystemNode::~CMapSystemNode()
/**********************************************/
{
}

/**********************************************/
void CMapSystemNode::InjectVisitor(CGraphVisitor& visitor)
/**********************************************/
{
    visitor.PerformOperation(*this); //Double dispatch
}

/**********************************************/
CProjected2DModel& CMapSystemNode::Projection()
/**********************************************/
{
    _projection->SetOriginParallel(ProjectionCenter().Lat());
    _projection->SetOriginMeridian(ProjectionCenter().Long());
    return(*_projection);
}

/**********************************************/
void CMapSystemNode::Projection(CProjected2DModel* projection)
/**********************************************/
{
    if(_projection)
        delete(_projection);
    _projection = projection;
}

/**********************************************/
CLatLongPoint CMapSystemNode::ProjectionCenter() const
/**********************************************/
{
    return(_projectionCenter);
}

/**********************************************/
void CMapSystemNode::ProjectionCenter(const CGeographicalPoint& center)
/**********************************************/
{
    _projectionCenter = center;
}

/**********************************************/
PROJECTED_MODEL_TYPE CMapSystemNode::ProjectionType() const
/**********************************************/
{
    return(_projectionType);
}

/**********************************************/
void CMapSystemNode::ProjectionType(PROJECTED_MODEL_TYPE projectionType)
/**********************************************/
{
    _projectionType = projectionType;
    UpdateProjection();
}

/**********************************************/
CWorld3DModel& CMapSystemNode::ReferenceEllipsoid()
/**********************************************/
{
    return(*_referenceEllipsoid);
}

/**********************************************/
void CMapSystemNode::ReferenceEllipsoid(CWorld3DModel* ellipsoid)
/**********************************************/
{
    if(_referenceEllipsoid)
        delete(_referenceEllipsoid);
    _referenceEllipsoid = ellipsoid;
}

/**********************************************/
WORLD_MODEL_TYPE CMapSystemNode::ReferenceEllipsoidType() const
/**********************************************/
{
    return(_referenceEllipsoidType);
}

/**********************************************/
void CMapSystemNode::ReferenceEllipsoidType(WORLD_MODEL_TYPE ellipsoidType)
/**********************************************/
{
    _referenceEllipsoidType = ellipsoidType;
    UpdateReferenceEllipsoid();
}

/**********************************************/
void CMapSystemNode::UpdateProjection()
/**********************************************/
{
    switch(ProjectionType())
    {
        case MERCATOR:
            Projection(new CMercatorProjection());
            break;
        case TRANSVERSE_MERCATOR:
            Projection(new CTransverseMercatorProjection());
            break;
        case STEREOGRAPHIC:
            Projection(new CStereographicProjection());
            break;
        case VERTICAL_PERSPECTIVE:
            Projection(new CVerticalPerspectiveProjection());
            break;
        case EQUIDISTANT_CONIC:
            Projection(new CEquidistantConicProjection());
            break;
        case GNOMONIC:
            Projection(new CGnomonicProjection());
            break;
        default:
            throw(CMochaException());
    };
}

/**********************************************/
void CMapSystemNode::UpdateReferenceEllipsoid()
/**********************************************/
{
    switch(ReferenceEllipsoidType())
    {
        case WGS_84:
            ReferenceEllipsoid(new CWGS84Model());
            break;
        case CLARKE_1866:
            ReferenceEllipsoid(new CClarke1866Model());
            break;
        case INTERNATIONAL:
            ReferenceEllipsoid(new CInternationalModel());
            break;
        default:
            throw(CMochaException());
    };
}

};
