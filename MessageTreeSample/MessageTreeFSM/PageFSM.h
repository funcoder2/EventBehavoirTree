#pragma once
#include "Page.h"
#include "..\Share\EventMessage.h"

class EventComponent;

class PageFSM
{
public:
	enum class StateType
	{
		None,	// 미작동
		Running,// 작동
		Finish,	// 마무리
	};

	using Ptr = std::shared_ptr<PageFSM>;

public:
	PageFSM();

public:
	void onTick(int tickIndex = 0, int interval = 0);
	void onMessage(EventMessage::Ptr message);
	void nextPage();
	void makeSample();

private:
	void init();
	void change(int nextId);
	void insert(Page::Ptr ptrPage);

private:
	std::map<int, Page::Ptr> pages_;
	Page::Ptr current_;
	StateType state_ = StateType::None;
};