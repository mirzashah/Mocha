#include <DOFNode.h>
#include <GraphVisitor.h>

namespace Mocha
{

/**********************************************/
CDOFNode::CDOFNode()
/**********************************************/
{
}

/**********************************************/
CDOFNode::~CDOFNode()
/**********************************************/
{
}

/**********************************************/
void CDOFNode::InjectVisitor(CGraphVisitor& visitor)
/**********************************************/
{
    visitor.PerformOperation(*this); //Double dispatch
}

};
