#include "osg/NodeVisitor"
#include <stdlib.h>

using namespace osg;

NodeVisitor::NodeVisitor(TraversalMode tm)
{
    _traversalVisitor = NULL;
    _traversalMode = tm;
}


NodeVisitor::~NodeVisitor()
{
    // if (_traversalVisitor) detach from _traversalVisitor;
}


void NodeVisitor::setTraversalMode(const TraversalMode mode)
{
    if (_traversalMode==mode) return;
    if (mode==TRAVERSE_VISITOR)
    {
        if (_traversalVisitor==NULL) _traversalMode = TRAVERSE_NONE;
        else _traversalMode = TRAVERSE_VISITOR;
    }
    else
    {
        if (_traversalVisitor.valid()) _traversalVisitor=NULL;
        _traversalMode = mode;
    }
}


void NodeVisitor::setTraversalVisitor(NodeVisitor* nv)
{
    if (_traversalVisitor==nv) return;
    _traversalVisitor = nv;
    if (_traversalVisitor.valid()) _traversalMode = TRAVERSE_VISITOR;
    else _traversalMode = TRAVERSE_NONE;
}
