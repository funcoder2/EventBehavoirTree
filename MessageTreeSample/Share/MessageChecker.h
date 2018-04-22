#pragma once
#include "..\Share\Checker.h"

namespace BrainTree {

	// GOAL: 메시지 기반으로 체크하는 조건자
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