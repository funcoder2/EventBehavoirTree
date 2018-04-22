// MessageTreeFSM.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Page.h"
#include "PageFSM.h"
#include "NextPageAction.h"

int main()
{
	// 1. fsm 선언
	auto pageFSM = std::make_shared<PageFSM>();

	// 2. 샘플 데이터 만들기
	// Desc: 3 Page, 3 Behavior Tree
	pageFSM->makeSample();

	// 3. 업데이트 
	const int INTERVAL = 500;
	for (int i = 0; i < 10; i++)
	{
		pageFSM->onTick(i, INTERVAL);
	}

    return 0;
}