#pragma once
#include "CkeyManager.h"

typedef struct MyKey
{
	
	CKeyManager::KEY_STATE curState; // 현재 키의 상태 값
	bool bIsPrev; // 이전 프레임에서 해당 키가 눌렸는지 여부

	// 리스트 인덱스 = 해당 키

}KEY;
