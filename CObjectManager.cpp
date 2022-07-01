#include "CObjectManager.h"

CObjectManager* CObjectManager::m_ObjMgr = nullptr; 
// Have to initialize static variables! (프로그램 생성과 동시에 초기화를 해주는데 자체가 없다면 오류)

CObjectManager::CObjectManager()
{

}

CObjectManager::~CObjectManager()
{

}

CObjectManager* CObjectManager::Get_Instance()
{
	if (!m_ObjMgr)
		m_ObjMgr = new CObjectManager;
	return m_ObjMgr;
}

void CObjectManager::Destroy_Instance()
{
	delete m_ObjMgr;
}

void CObjectManager::Init()
{
	
}

void CObjectManager::Update()
{
	for (COBJ_MAP::iterator mapiter = m_ObjMap.begin(); mapiter != m_ObjMap.end(); ++mapiter)
	{
		for (COBJ_LIST::iterator iter = mapiter->second.begin(); iter != mapiter->second.end(); ++iter)
		{
			(*iter)->Update();
		}
	}
}

void CObjectManager::LateUpdate()
{
	for (COBJ_MAP::iterator mapiter = m_ObjMap.begin(); mapiter != m_ObjMap.end(); ++mapiter)
	{
		for (COBJ_LIST::iterator iter = mapiter->second.begin(); iter != mapiter->second.end(); ++iter)
		{
			(*iter)->LateUpdate();
		}
	}
}

void CObjectManager::Render()
{
	for (COBJ_MAP::iterator mapiter = m_ObjMap.begin(); mapiter != m_ObjMap.end(); ++mapiter)
	{
		for (COBJ_LIST::iterator iter = mapiter->second.begin(); iter != mapiter->second.end(); ++iter)
		{
			(*iter)->Render();
		}
	}
}

void CObjectManager::Add_CObject(OBJECT_TYPE type, CObject* temp)
{
	if (temp == nullptr)
		return;

	COBJ_MAP::iterator iter = m_ObjMap.find(type);

	if (iter == m_ObgMap.end())
	{
		COBJ_LIST listtemp;
		listtemp.push_back(temp);
		m_ObgMap.insert({ type, listtemp });
		return;
	}

	iter->second.push_back(temp);
}

/*

	메인 시작 초기화때, 플레이어-브릭 생성 애드
	
	이후 총알과 화살표는 add 오브젝트로 생성

*/
