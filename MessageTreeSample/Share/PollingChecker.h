#pragma once
#include "Checker.h"

namespace BrainTree {

	// GOAL: ƽ Or ������Ʈ�� ������� üũ�ϴ� ������.
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