#include "stdafx.h"
#include "Page.h"
#include "NextPageAction.h"

Page::Page(int pageId, PageFSM* owner)
: pageId_(pageId)
,owner_(owner)
{

}

Page::~Page()
{

}

void Page::onStart()
{
	UTIL::doLog("===[Page Start:", pageId_,"]===");
}

void Page::onUpdate()
{
	// Not
	if (!behaviorTree_.hasRoot())
	{
		return;
	}

	// is Terminated ?
	if (behaviorTree_.isTerminatedRoot())
	{
		return;
	}

	behaviorTree_.update();
}

void Page::onEnd()
{
	UTIL::doLog("===[Page End:", pageId_, "]===");
}

void Page::onMessage(EventMessage::Ptr message)
{
	// Not
	if (!behaviorTree_.hasRoot())
	{
		return;
	}

	// is Terminated ?
	if (behaviorTree_.isTerminatedRoot())
	{
		return;
	}

	behaviorTree_.onMessage(message);
}

void Page::makeSample()
{
	const int TEST_COUNT = 2;

	if (!behaviorTree_.hasRoot())
	{
		auto sequence = std::make_shared<BrainTree::Sequence>();
		auto updateCountChecker= std::make_shared<BrainTree::UpdateCountChecker>(TEST_COUNT);
		auto action = std::make_shared<BrainTree::Action>();
		auto nextPageAction = std::make_shared<BrainTree::NextPageAction>(this);

		sequence->addChild(updateCountChecker);
		sequence->addChild(action);
		sequence->addChild(nextPageAction);

		// 루트 지정
		setRoot(sequence);
	}
}

void Page::setRoot(const BrainTree::Node::Ptr &node)
{
	behaviorTree_.setRoot(node);
}