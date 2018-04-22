#include "stdafx.h"
#include "EventDataFctory.h"

EventDataFctory::EventDataFctory()
{

}

EventDataFctory::~EventDataFctory()
{

}

void EventDataFctory::makeSampleDataMessage(std::queue<EventMessage::Ptr>& messageQueue)
{
	// 10번, 11번, 12번 지형 트리거 스위치 ON
	messageQueue.push(std::make_shared<TerrainInMessage>(SENDER_ID, RECEIVER_ID, AREA_ID_1));
	messageQueue.push(std::make_shared<TerrainInMessage>(SENDER_ID, RECEIVER_ID, AREA_ID_2));
	messageQueue.push(std::make_shared<TerrainInMessage>(SENDER_ID, RECEIVER_ID, AREA_ID_3));

	// NPCID 5001, 킬 메시지 3번
	messageQueue.push(std::make_shared<KillNpcMessage>(SENDER_ID, RECEIVER_ID, NPC_ID));
	messageQueue.push(std::make_shared<KillNpcMessage>(SENDER_ID, RECEIVER_ID, NPC_ID));
	messageQueue.push(std::make_shared<KillNpcMessage>(SENDER_ID, RECEIVER_ID, NPC_ID));
}

void EventDataFctory::makeSampleDataBehaviorTree(BrainTree::BehaviorTree& behaviorTree)
{
	auto sequence = std::make_shared<BrainTree::Sequence>();

	// In 지역 체커
	auto messageTerrainChecker1 = std::make_shared<BrainTree::AreaInChecker>(AREA_ID_1);
	auto messageTerrainChecker3 = std::make_shared<BrainTree::AreaInChecker>(AREA_ID_3);

	// 킬 카운트
	auto messageKillCountChecker = std::make_shared<BrainTree::KillCountChecker>(NPC_ID, MAX_COUNT);

	// 업데이트 카운트함.
	auto pollingUpdateCountChecker = std::make_shared<BrainTree::UpdateCountChecker>(MAX_COUNT);

	sequence->addChild(messageTerrainChecker1);
	sequence->addChild(messageTerrainChecker3);
	sequence->addChild(messageKillCountChecker);
	sequence->addChild(pollingUpdateCountChecker);

	auto action = std::make_shared<BrainTree::Action>();
	sequence->addChild(action);

	// 루트 지정.
	behaviorTree.setRoot(sequence);
}
