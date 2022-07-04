#include "stdfx.h"
#include "CObjectManager.h"

CObjectManager* CObjectManager::m_ObjMgr = nullptr; 
// Have to initialize static variables! (���α׷� ������ ���ÿ� �ʱ�ȭ�� ���ִµ� ��ü�� ���ٸ� ����)

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
	/*

	�÷��̾�� �긯�� �̸� �� Ÿ�ֿ̹� ����

	*/
	Vector2 tempVec = { CPLAYER_START_POS_X, CPLAYER_START_POS_Y };
	CPlayer* tempCPlayer = new CPlayer(tempVec);
	Add_CObject(OBJECT_TYPE::CPLAYER, tempCPlayer);

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

void CObjectManager::Render(HDC hdc)
{
	for (COBJ_MAP::iterator mapiter = m_ObjMap.begin(); mapiter != m_ObjMap.end(); ++mapiter)
	{
		for (COBJ_LIST::iterator iter = mapiter->second.begin(); iter != mapiter->second.end(); ++iter)
		{
			(*iter)->Render(hdc);
		}
	}
}

void CObjectManager::Add_CObject(OBJECT_TYPE type, CObject* temp)
{
	if (temp == nullptr)
		return;

	COBJ_MAP::iterator iter = m_ObjMap.find(type);

	if (iter == m_ObjMap.end())
	{
		COBJ_LIST listtemp;
		listtemp.push_back(temp);
		m_ObjMap.insert({ type, listtemp });
		return;
	}

	iter->second.push_back(temp);
}

/*

	���� ���� �ʱ�ȭ��, �÷��̾�-�긯 ���� �ֵ�
	
	���� �Ѿ˰� ȭ��ǥ�� add ������Ʈ�� ����

*/
