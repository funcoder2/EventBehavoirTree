#include "stdafx.h"
#include "PageFSM.h"

PageFSM::PageFSM() 
{

}

void PageFSM::onTick(int tickIndex /*= 0*/, int interval /*= 0*/)
{
	if (state_ == StateType::None)
	{
		// 상태 변경
		state_ = StateType::Running;

		// 초기화
		init();
	}

	if (current_ != nullptr)
	{
		current_->onUpdate();
	}
	else
	{
		UTIL::doLog("FSM:", __FUNCTION__, "Current Reference: Fail");
	}

	// 로그 편의를 위해 지연 처리. (불필요시 삭제)
	if (interval != 0)
	{
		Sleep(interval);
	}
}

void PageFSM::onMessage(EventMessage::Ptr message)
{
	if (current_ == nullptr)
	{
		UTIL::doLog("FSM:", __FUNCTION__, "Current Reference: Fail");
	}
	else
	{
		current_->onMessage(message);
	}
}

void PageFSM::nextPage()
{
	if (current_ == nullptr)
	{
		UTIL::doLog("FSM:", __FUNCTION__, "Page Reference: Fail");

		return;
	}

	auto it = pages_.find(current_->getPageId());
	if (it == pages_.end())
	{
		return;
	}

	auto next_it = std::next(it);
	if (next_it != pages_.end())
	{
		// 다음으로 진행
		change(next_it->first);
	}
	else
	{
		UTIL::doLog("FSM:", "No More Page");
	}
}

void PageFSM::makeSample()
{
	// 테스트 BT 생성
	int startId = 1;
	for (int i = 0; i <= 2; i++)
	{
		auto page = std::make_shared<Page>(startId+i, this);

		page->makeSample();

		// 주입
		insert(page);
	}
}

void PageFSM::init()
{
	if (!pages_.empty())
	{
		auto first = pages_.begin()->second;
		current_ = first;

		// 초기화와 START 호출
		current_->onStart();
	}
	else
	{
		UTIL::doLog("FSM:", "Init Fail");
	}
}

void PageFSM::change(int nextId)
{
	if (current_ == nullptr)
	{
		UTIL::doLog("FSM:", __FUNCTION__, "Page Reference: Fail");
		return;
	}

	auto it = pages_.find(nextId);
	if (it == pages_.end())
	{
		UTIL::doLog("FSM:", __FUNCTION__, "Find: Fail");
		return;
	}

	// 로그
	UTIL::doLog("FSM:","Try Change Page:", current_->getPageId(), "->", nextId);

	// 현재 END
	current_->onEnd();

	// 교cp
	current_ = it->second;

	// 변경 PAGE 시작
	current_->onStart();
}

void PageFSM::insert(Page::Ptr ptrPage)
{
	auto it = pages_.insert(std::make_pair(ptrPage->getPageId(), ptrPage));
	if (!it.second)
	{
		UTIL::doLog("FSM:","Insert Fail", ptrPage->getPageId());
	}
}