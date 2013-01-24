#include <DOMNode.h>
#include <GraphVisitor.h>

namespace Mocha
{

/**********************************************/
CDOMNode::CDOMNode()
/**********************************************/
{
}

/**********************************************/
CDOMNode::~CDOMNode()
/**********************************************/
{
}

/**********************************************/
void CDOMNode::InjectVisitor(CGraphVisitor& visitor)
/**********************************************/
{
    visitor.PerformOperation(*this); //Double dispatch
}

};
