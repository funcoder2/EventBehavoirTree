#pragma once
#include "..\Share\PollingChecker.h"

namespace BrainTree {

	// GOAL: 업데이트 횟수를 카운팅한다.
	class UpdateCountChecker : public PollingChecker
	{
	public:
		UpdateCountChecker(int maxCount)
			:maxCount_(maxCount)
		{
		}
		virtual ~UpdateCountChecker() {}

	private:
		// 체크 로직
		bool check(EventMessage::Ptr message) override
		{
			bool result = false;

			do
			{
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
			printf("Polling, Update_Count Checker (Count:%d/%d) State:%s\n", 
				count_, maxCount_, result ? "Success" : "Run");
		}

	protected:
		int count_ = 0;
		int maxCount_ = 0;
	};
}