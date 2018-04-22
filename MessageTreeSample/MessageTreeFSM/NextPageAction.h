#pragma once
#include "..\Share\Action.h"
#include "PageFSM.h"

namespace BrainTree {
	
	// ���� �������� ��ȯ
	class NextPageAction : public Action
	{
	public:
		NextPageAction(Page* page) : onwer_(page) {}
		virtual ~NextPageAction() {}

		Status update() override
		{
			printf("Action, NextPageAction\n");

			// FSM�� ȣ��
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