#include "CObjectManager.h"

CObjectManager* CObjectManager::m_ObjMgr = nullptr; // Have to initialize static variables!

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
}

void CObjectManager::LateUpdate()
{
}

void CObjectManager::Render()
{
}
