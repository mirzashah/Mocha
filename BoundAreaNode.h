/*****************************************************************************/
// Filename: BoundVolumeNode.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef MOCHA_BOUND_AREA_NODE_H_DEFINED
#define MOCHA_BOUND_AREA_NODE_H_DEFINED

#include <SceneNode.h>

namespace Mocha
{

class CBoundAreaNode: public CSceneNode
{
    public:
        CBoundAreaNode();
        virtual ~CBoundAreaNode();

        virtual bool IsMouseOverArea(CCartesianPoint mousePosition) = 0;

    private:
        virtual void InjectVisitor(CGraphVisitor& visitor);

};
};

#endif
