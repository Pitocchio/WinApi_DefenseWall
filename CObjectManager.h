#pragma once

class CObject;
/*
#include 관련
if Manager라면 매니지 하는 대상의 헤더파일을 클래스 전방선언
CObjectManager -> CObject 전방선언
*/

class CObjectManager
{
private:
	CObjectManager();
	~CObjectManager();

public: // SingleTone
	static CObjectManager* Get_Instance();
	static void Destroy_Instance();

public: // Life Cycle
	void Init();
	void Update(); // Collision check
	void LateUpdate(); // Collision implement
	void FixedUpdate();
	void Render(HDC hdc);

public: // Method
	void Add_CObject(OBJECT_TYPE, CObject*);
	COBJ_MAP Get_ObjectMap() const { return m_ObjMap; }

private: // Variables
	static CObjectManager* m_ObjMgr;
	COBJ_MAP m_ObjMap;
};