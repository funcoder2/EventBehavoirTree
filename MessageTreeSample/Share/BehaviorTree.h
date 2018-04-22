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
	// 주기 처리
    Status update() { return root->tick(); }

	// 이벤트 드리븐 처리
	Status updateMessage(EventMessage::Ptr message)
	{
		return root->onMessage(message);
	}

	// 루트 상태
	bool hasRoot() {
		return root != nullptr;
	}

	// 종료 되었나?
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
