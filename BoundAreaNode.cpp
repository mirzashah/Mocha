#include <BoundAreaNode.h>
#include <GraphVisitor.h>

namespace Mocha
{

/**********************************************/
CBoundAreaNode::CBoundAreaNode()
/**********************************************/
{
}

/**********************************************/
CBoundAreaNode::~CBoundAreaNode()
/**********************************************/
{
}

/**********************************************/
void CBoundAreaNode::InjectVisitor(CGraphVisitor& visitor)
/**********************************************/
{
    visitor.PerformOperation(*this); //Double dispatch
}

};
