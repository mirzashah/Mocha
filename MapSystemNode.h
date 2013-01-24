/*****************************************************************************/
// Filename: MapSystemNode.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef MAP_SYSTEM_NODE_H_DEFINED
#define MAP_SYSTEM_NODE_H_DEFINED

#include <SceneNode.h>
#include <MapSystemCore.h>

namespace Mocha
{

class CMapSystemNode: public CSceneNode
{
    public:
        CMapSystemNode(WORLD_MODEL_TYPE referenceEllipsoidType, PROJECTED_MODEL_TYPE projectionType, CGeographicalPoint projectionCenter);
        virtual ~CMapSystemNode();

        CProjected2DModel&   Projection();
        CLatLongPoint        ProjectionCenter() const;
        void                 ProjectionType(PROJECTED_MODEL_TYPE projectionType);
        void                 ProjectionCenter(const CGeographicalPoint& center);
        CWorld3DModel&       ReferenceEllipsoid();
        void                 ReferenceEllipsoidType(WORLD_MODEL_TYPE ellipsoidType);

    private:
        virtual void         InjectVisitor(CGraphVisitor& visitor);
        void                 Projection(CProjected2DModel* projection);
        PROJECTED_MODEL_TYPE ProjectionType() const;
        void                 ReferenceEllipsoid(CWorld3DModel* ellipsoid);
        WORLD_MODEL_TYPE     ReferenceEllipsoidType() const;
        void                 UpdateProjection();
        void                 UpdateReferenceEllipsoid();

    private:
        CWorld3DModel*       _referenceEllipsoid;
        WORLD_MODEL_TYPE     _referenceEllipsoidType;
        CProjected2DModel*   _projection;
        PROJECTED_MODEL_TYPE _projectionType;
        CGeographicalPoint   _projectionCenter;
};
};

#endif
