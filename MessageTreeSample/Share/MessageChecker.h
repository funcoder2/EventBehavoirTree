#pragma once
#include "..\Share\Checker.h"

namespace BrainTree {

	// GOAL: �޽��� ������� üũ�ϴ� ������
	class MessageChecker : public Checker
	{
	public:
		MessageChecker() {}
		MessageChecker(Blackboard::Ptr blackboard)
			: Checker(blackboard)
		{
		}
		virtual ~MessageChecker() {}

	public:
		Status updateMessage(EventMessage::Ptr message) override
		{
			if (check(message))
			{
				return Status::Success;
			}

			return status;
		}
	};
}