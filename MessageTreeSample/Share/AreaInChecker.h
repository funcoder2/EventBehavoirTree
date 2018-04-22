#pragma once
#include "..\Share\MessageChecker.h"

namespace BrainTree {

	// GOAL: Ư�� ���� ������ ��� �Դ��� üũ 
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

			// �α�
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