#include <GeoNode.h>
#include <BoundAreaNode.h>
#include <GraphVisitor.h>

namespace Mocha
{

/**********************************************/
CGeoNode::CGeoNode() :
_optionalBoundArea(NULL)
/**********************************************/
{
}

/**********************************************/
CGeoNode::~CGeoNode()
/**********************************************/
{
}

/**********************************************/
void CGeoNode::InjectVisitor(CGraphVisitor& visitor)
/**********************************************/
{
    visitor.PerformOperation(*this); //Double dispatch
}

/*********************************************/
CBoundAreaNode* CGeoNode::OptionalBoundArea()
/*********************************************/
{
    return(_optionalBoundArea);
}

/*********************************************/
void CGeoNode::OptionalBoundArea(CBoundAreaNode* boundArea)
/*********************************************/
{
    if(_optionalBoundArea)
        delete(_optionalBoundArea);
    _optionalBoundArea = boundArea;
}
};
