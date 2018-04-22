#pragma once
#include "..\Share\MessageChecker.h"

namespace BrainTree {

	// GOAL: 특정 영역 안으로 들어 왔는지 체크 
	class AreaInChecker : public MessageChecker
	{
	public:
		AreaInChecker(int terrainId)
			: terrainId_(terrainId)
		{
		}
		virtual ~AreaInChecker() {}

	private:
		bool check(EventMessage::Ptr message) override
		{
			bool result = false;

			do
			{
				if (message->getId() != MessageId::TERRAIN_IN)
				{
					break;
				}

				auto terrainInMessage = static_cast<TerrainInMessage*>(message.get());
				if (terrainInMessage->getTerrainId() != terrainId_)
				{
					break;
				}

				result = true;

			} while (false);

			// 로그
			doLog(result);

			return result;
		}

		void doLog(bool result)
		{
			printf("Message, Area_In Checker(%d) State:%s\n", terrainId_, result ? "Success" : "Run");
		}

	protected:
		int terrainId_ = 0;
	};
}