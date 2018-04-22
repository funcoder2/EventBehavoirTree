#pragma once
#include "MessageChecker.h"

namespace BrainTree {

	// GOAL: 업데이트 횟수를 카운팅한다.
	class KillCountChecker : public MessageChecker
	{
	public:
		KillCountChecker(int targetNpcId, int maxCount)
			:targetNpcId_(targetNpcId), maxCount_(maxCount)
		{
		}
		virtual ~KillCountChecker() {}

	private:
		// 체크 로직
		bool check(EventMessage::Ptr message) override
		{
			bool result = false;

			do
			{
				if (message->getId() != MessageId::KILL_NPC)
				{
					break;
				}

				auto killNpcMessage = static_cast<KillNpcMessage*>(message.get());
				if (targetNpcId_ != killNpcMessage->getNpcId())
				{
					break;
				}

				// 증가 가능함?
				if (count_ < maxCount_)
				{
					count_++;
				}

				if (count_ != maxCount_)
				{
					break;
				}

				result = true;

			} while (false);

			// 로그 출력
			doLog(result);

			return result;
		}

		// 로그
		void doLog(bool result)
		{
			printf("Message, Kill_Count Checker(Target:%d/Count:%d/%d) State:%s\n",
				targetNpcId_, count_, maxCount_, result ? "Success":"Run");
		}

	protected:
		int targetNpcId_ = 0;
		int count_ = 0;
		int maxCount_ = 0;
	};
}