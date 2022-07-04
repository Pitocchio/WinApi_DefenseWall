#include "stdfx.h"
#include "CkeyManager.h"

CKeyManager* CKeyManager::m_KeyMgr = nullptr;

CKeyManager::CKeyManager()
{
}

CKeyManager::~CKeyManager()
{
}

CKeyManager* CKeyManager::Get_Instance()
{
	if (!m_KeyMgr)
		m_KeyMgr = new CKeyManager; 
	return m_KeyMgr;
}

void CKeyManager::Destroy_Instance()
{
	delete m_KeyMgr;
}

void CKeyManager::Init()
{
}

void CKeyManager::Update()
{
}

void CKeyManager::LateUpdate()
{
}


