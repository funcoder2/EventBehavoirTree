#pragma once

#include "..\Share\Node.h"
#include "..\Share\Blackboard.h"

namespace BrainTree {

class Leaf : public Node
{
public:
    Leaf() {}
    virtual ~Leaf() {}
    Leaf(Blackboard::Ptr blackboard) : blackboard(blackboard) {}
    
    virtual Status update() = 0;
    virtual Status updateMessage(EventMessage::Ptr message) = 0;

protected:
    Blackboard::Ptr blackboard;
};

} // BrainTree
