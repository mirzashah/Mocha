/*****************************************************************************/
// Filename: DOMNode.h
/*****************************************************************************/
// Description: 
/*****************************************************************************/

#ifndef DOM_NODE_H_DEFINED
#define DOM_NODE_H_DEFINED

#include <SceneNode.h>

namespace Mocha
{

class CDOMNode : public CSceneNode
{
    friend class CPickVisitor;
    friend class CRenderVisitor;
    friend class CUpdateVisitor;

    public:
        CDOMNode();
        virtual ~CDOMNode();
    
    protected:
        virtual void ApplyTransformation() = 0;
        virtual void UndoTransformation() = 0;

    private:
        virtual void InjectVisitor(CGraphVisitor& visitor);

};
};

#endif
