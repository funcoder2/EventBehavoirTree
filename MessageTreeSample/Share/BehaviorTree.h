#pragma once

#include "Node.h"
#include "Blackboard.h"

namespace BrainTree {

class BehaviorTree : public Node
{
public:
    BehaviorTree() : blackboard(std::make_shared<Blackboard>()) {}
    BehaviorTree(const Node::Ptr &rootNode) : BehaviorTree() { root = rootNode; }
    
public:
	// �ֱ� ó��
    Status update() { return root->tick(); }

	// �̺�Ʈ �帮�� ó��
	Status updateMessage(EventMessage::Ptr message)
	{
		return root->onMessage(message);
	}

	// ��Ʈ ����
	bool hasRoot() {
		return root != nullptr;
	}

	// ���� �Ǿ���?
	bool isTerminatedRoot()
	{
		return root->isTerminated();
	}

public:
    void setRoot(const Node::Ptr &node) { root = node; }
    Blackboard::Ptr getBlackboard() const { return blackboard; }
    
private:
    Node::Ptr root = nullptr;
    Blackboard::Ptr blackboard = nullptr;
};

} // BrainTree
