#pragma once
#include "CkeyManager.h"

typedef struct MyKey
{
	
	CKeyManager::KEY_STATE curState; // ���� Ű�� ���� ��
	bool bIsPrev; // ���� �����ӿ��� �ش� Ű�� ���ȴ��� ����

	// ����Ʈ �ε��� = �ش� Ű

}KEY;
