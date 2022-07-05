/*
#pragma once

class CKeyManager
{



//KeyManager의 필요성

//1. 프레임 동기화 (한 프레임에서 발생한 일들은 동일한 키 입력에 대해서 동일한 상태로 반영

//2. 키 입력을 구체적으로 사용자 정의 처리 ex. tap, hold, away


public: // Enum
	enum class KEY_TYPE {SPACE, LEFT, RIGHT, ESC, KEYTYPEEND};
	enum class KEY_STATE {NONE, TAP, HOLD, AWAY, KEYSTATEEND};
	
	//TAP  : 이전 프레임 X, 현재 프레임 O
	//HOLD : 이전 프레임 O, 현재 프레임 O
	//AWAY : 이전 프레임 O, 현재 프레임 X
	//NONE : 이전 프레임 O, 현재 프레임 O
	

private:
	CKeyManager();
	~CKeyManager();

public: // SingleTone
	static CKeyManager* Get_Instance();
	static void Destroy_Instance();

public: 
	void Init();
	void Update();
	void LateUpdate();

private: // Variables
	static CKeyManager* m_KeyMgr;
	list<KEY> m_listKey;
};

*/