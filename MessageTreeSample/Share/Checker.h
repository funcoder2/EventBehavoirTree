#pragma once
#include "..\Share\Leaf.h"

namespace BrainTree {

	// �޽��� ó����
	class Checker : public Leaf
	{
	public:
		Checker() {}
		virtual ~Checker() {}
		Checker(Blackboard::Ptr blackboard) : blackboard(blackboard) {}

		void initialize() override
		{
			status = Status::Running;
		}

		Status update() override
		{
			return status;
		}

	protected:
		virtual bool check(EventMessage::Ptr message) = 0;

	protected:
		Blackboard::Ptr blackboard;
	};

} // BrainTree
