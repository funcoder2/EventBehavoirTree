// MessageTree.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "EventDataFctory.h"

int main()
{
	/// 1. [테스트 메시지 만들기]
	// 메시지 큐
	std::queue<EventMessage::Ptr> messageQueue;

	// 테스트 메시지 생성
	EventDataFctory::makeSampleDataMessage(messageQueue);
	
	/// 2. [간단한 BT 만들기]
	// 트리 생성
	BrainTree::BehaviorTree behaviorTree;

	// 테스트 행동 트리 생성
	EventDataFctory::makeSampleDataBehaviorTree(behaviorTree);

	/// 3. [업데이트 처리]
	for (int i  = 0; i < 10; i++)
	{
		// Not
		if (!behaviorTree.hasRoot())
		{
			UTIL::doLog("BehaviorTree Root is Null");

			continue;
		}

		if (behaviorTree.isTerminatedRoot())
		{
			UTIL::doLog("BehaviorTree is Terminated");
	
			continue;
		}

		/// 폴링과 이벤트 드리븐 같이 처리
		// A. 이벤트 드리븐 처리
		if (!messageQueue.empty())
		{
			auto message = messageQueue.front();
			messageQueue.pop();

			behaviorTree.updateMessage(message);
		}

		// B. 폴링 처리
		behaviorTree.update();
	}

    return 0;
}
