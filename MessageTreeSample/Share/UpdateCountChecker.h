#pragma once
#include "..\Share\PollingChecker.h"

namespace BrainTree {

	// GOAL: ������Ʈ Ƚ���� ī�����Ѵ�.
	class UpdateCountChecker : public PollingChecker
	{
	public:
		UpdateCountChecker(int maxCount)
			:maxCount_(maxCount)
		{
		}
		virtual ~UpdateCountChecker() {}

	private:
		// üũ ����
		bool check(EventMessage::Ptr message) override
		{
			bool result = false;

			do
			{
				// ���� ������?
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

			// �α� ���
			doLog(result);

			return result;
		}

		// �α�
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