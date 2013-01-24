/*****************************************************************************/
// Filename: GeoNode.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef GEO_NODE_H_DEFINED
#define GEO_NODE_H_DEFINED

#include <SceneNode.h>

namespace Mocha
{

class CGeoNode : public CSceneNode
{
    friend class CEventVisitor;
    friend class CRenderVisitor;
    friend class CUpdateVisitor;

    public:
        CGeoNode();
        virtual ~CGeoNode();

    protected:
        virtual void    DrawMe(){};
        CBoundAreaNode* OptionalBoundArea();
        void            OptionalBoundArea(CBoundAreaNode* boundArea);

    private:
        virtual void    InjectVisitor(CGraphVisitor& visitor);

    private:
        CBoundAreaNode* _optionalBoundArea;

};
};

#endif
