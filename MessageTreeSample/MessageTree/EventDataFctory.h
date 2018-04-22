#pragma once
#include <queue>
#include "..\Share\EventMessage.h"
#include "..\Share\BehaviorTree.h"

// ���� �����͸� �����
class EventDataFctory
{
public:
	const static int SENDER_ID = 1000;
	const static int RECEIVER_ID = 2000;
	const static int AREA_ID_1 = 10;
	const static int AREA_ID_2 = 11;
	const static int AREA_ID_3 = 12;
	const static int NPC_ID = 5001;
	const static int MAX_COUNT = 2;

public:
	EventDataFctory();
	~EventDataFctory();

public:
	// ���� �޽��� ������ �����
	static void makeSampleDataMessage(std::queue<EventMessage::Ptr>& messageQueue);

	// ���� �ൿ Ʈ�� ������ �����
	static void makeSampleDataBehaviorTree(BrainTree::BehaviorTree& behaviorTree);
};