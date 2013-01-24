/*****************************************************************************/
// Filename: RotateNode.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef ROTATE_NODE_H_DEFINED
#define ROTATE_NODE_H_DEFINED

#include <DOFNode.h>
namespace Mocha
{

class CRotateNode : public CDOFNode
{
    public:
        CRotateNode(double angleInDegrees, double rotateAxisX, double rotateAxisY);
        virtual ~CRotateNode();

        double       AngleInDegrees() const;
        void         AngleInDegrees(double deg);
        double       RotateAxisX() const;
        void         RotateAxisX(double deg);
        double       RotateAxisY() const;
        void         RotateAxisY(double deg);

    protected:
        virtual void ApplyTransformation();
        virtual void UndoTransformation();

    private:
        double       _angleInDegrees;
        double       _rotateAxisX;
        double       _rotateAxisY;
};

};


#endif
