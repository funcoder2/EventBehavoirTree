// MessageTree.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "EventDataFctory.h"

int main()
{
	/// 1. [�׽�Ʈ �޽��� �����]
	// �޽��� ť
	std::queue<EventMessage::Ptr> messageQueue;

	// �׽�Ʈ �޽��� ����
	EventDataFctory::makeSampleDataMessage(messageQueue);
	
	/// 2. [������ BT �����]
	// Ʈ�� ����
	BrainTree::BehaviorTree behaviorTree;

	// �׽�Ʈ �ൿ Ʈ�� ����
	EventDataFctory::makeSampleDataBehaviorTree(behaviorTree);

	/// 3. [������Ʈ ó��]
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

		/// ������ �̺�Ʈ �帮�� ���� ó��
		// A. �̺�Ʈ �帮�� ó��
		if (!messageQueue.empty())
		{
			auto message = messageQueue.front();
			messageQueue.pop();

			behaviorTree.updateMessage(message);
		}

		// B. ���� ó��
		behaviorTree.update();
	}

    return 0;
}
