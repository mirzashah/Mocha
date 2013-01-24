/*****************************************************************************/
// Filename: ScaleNode.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef SCALE_NODE_H_DEFINED
#define SCALE_NODE_H_DEFINED

#include <DOFNode.h>
namespace Mocha
{

class CScaleNode : public CDOFNode
{
    public:
        CScaleNode(double scaleX, double scaleY);
        virtual ~CScaleNode();

        double ScaleX() const;
        void   ScaleX(double scaleX);
        double ScaleY() const;
        void   ScaleY(double scaleY);

    protected:
        virtual void ApplyTransformation();
        virtual void UndoTransformation();

    private:
        double _scaleX;
        double _scaleY;


};

};


#endif
