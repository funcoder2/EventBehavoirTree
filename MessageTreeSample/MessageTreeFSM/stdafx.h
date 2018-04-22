// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <functional>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <memory>
#include <windows.h>
#include <map>
#include <iostream>

#include "..\Share\BehaviorTree.h"
#include "..\Share\Util.h"
#include "..\Share\composites\Sequence.h"
#include "..\Share\MessageIdEnum.h"
#include "..\Share\EventMessage.h"
#include "..\Share\Checker.h"
#include "..\Share\Action.h"
#include "..\Share\MessageChecker.h"
#include "..\Share\PollingChecker.h"
#include "..\Share\UpdateCountChecker.h"
#include "..\Share\AreaInChecker.h"
#include "..\Share\KillCountChecker.h"
