/*****************************************************************************/
// Filename: DOFNode.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef DOM_NODE_H_DEFINED
#define DOM_NODE_H_DEFINED

#include <SceneNode.h>

namespace Mocha
{

class CDOFNode : public CSceneNode
{
    friend class CEventVisitor;
    friend class CRenderVisitor;
    friend class CUpdateVisitor;

    public:
        CDOFNode();
        virtual ~CDOFNode();

    protected:
        virtual void ApplyTransformation() = 0;
        virtual void UndoTransformation() = 0;

    private:
        virtual void InjectVisitor(CGraphVisitor& visitor);

};
};

#endif
