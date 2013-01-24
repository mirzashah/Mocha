/*****************************************************************************/
// Filename: TranslateNode.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef TRANSLATE_NODE_H_DEFINED
#define TRANSLATE_NODE_H_DEFINED

#include <DOFNode.h>
namespace Mocha
{

class CTranslateNode : public CDOFNode
{
    public:
        CTranslateNode(double translateX, double translateY);
        virtual ~CTranslateNode();
        double TranslateX() const;
        void   TranslateX(double translateX);
        double TranslateY() const;
        void   TranslateY(double translateY);

    protected:
        virtual void ApplyTransformation();
        virtual void UndoTransformation();

    private:
        double _translateX;
        double _translateY;

};

};


#endif
