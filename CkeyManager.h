#pragma once

/*

KeyManager�� �ʿ伺

1. ������ ����ȭ (�� �����ӿ��� �߻��� �ϵ��� ������ Ű �Է¿� ���ؼ� ������ ���·� �ݿ�

2. Ű �Է��� ��ü������ ����� ���� ó�� ex. tap, hold, away

*/
class CKeyManager
{
public: // Enum
	enum class KEY_TYPE {SPACE, LEFT, RIGHT, ESC, KEYTYPEEND};
	enum class KEY_STATE {NONE, TAP, HOLD, AWAY, KEYSTATEEND};
	/*
	TAP  : ���� ������ X, ���� ������ O
	HOLD : ���� ������ O, ���� ������ O
	AWAY : ���� ������ O, ���� ������ X
	NONE : ���� ������ O, ���� ������ O
	*/

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