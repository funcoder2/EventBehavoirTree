#pragma once
#include "..\Share\Action.h"
#include "PageFSM.h"

namespace BrainTree {
	
	// 다음 페이지로 전환
	class NextPageAction : public Action
	{
	public:
		NextPageAction(Page* page) : onwer_(page) {}
		virtual ~NextPageAction() {}

		Status update() override
		{
			printf("Action, NextPageAction\n");

			// FSM을 호출
			auto fsm = onwer_->getOwner();
			if (fsm != nullptr)
			{
				fsm->nextPage();
			}

			return Status::Success;
		}

	protected:
		Blackboard::Ptr blackboard;
		Page* onwer_ = nullptr;
	};
}