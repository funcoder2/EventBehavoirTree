#pragma once
#include "Checker.h"

namespace BrainTree {

	// GOAL: 틱 Or 업데이트를 기반으로 체크하는 조건자.
	class PollingChecker : public Checker
	{
	public:
		PollingChecker() {}
		PollingChecker(Blackboard::Ptr blackboard)
			: Checker(blackboard)
		{
		}
		virtual ~PollingChecker() {}

	public:
		Status updateMessage(EventMessage::Ptr message) override
		{
			/* empty */
			return status;
		}

		Status update() override
		{
			if (check(nullptr))
			{
				return Status::Success;
			}
			return status;
		}
	};
}