#include "stdfx.h"
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
	/* CPlayer 생성 */
	Vector2 tempCPlayerVec = { CPLAYER_START_POS_X, CPLAYER_START_POS_Y };
	CPlayer* tempCPlayer = new CPlayer(tempCPlayerVec, CPLAYER_RADIUS, CPLAYER_GUN_DISTANCE);
	Add_CObject(OBJECT_TYPE::CPLAYER, tempCPlayer);


	/* CWall 생성 */
	Vector2 tempCWallVec = { CWALL_WIDTH * 0.5, WINDOW_HEIGHT - CWALL_HEIGHT };
	for (int i = 0; i < CWALL_NUM; ++i)
	{
		CWall* tempCWall = new CWall(tempCWallVec);
		Add_CObject(OBJECT_TYPE::CWALL, tempCWall);
		tempCWallVec.x += CWALL_WIDTH;
	}
}

void CObjectManager::Update()
{
	///* CEnemy 생성*/
	//Vector2 tempCEnemyVec = { rand() % (WINDOW_WIDTH - 80) + 80, CENEMY_START_POS_Y };
	//CEnemy* tempCEnemy = new CEnemy(tempCEnemyVec, CENEMY_RADIUS, CENEMY_DISTANCE);
	//Add_CObject(OBJECT_TYPE::CENEMY, tempCEnemy);

	/* Update */
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
	CollisionMnager::Get_Instance()->Check_Collision(CollisionMnager::COLLISION_TYPE::CIRCLE2D, OBJECT_TYPE::CBULLET, OBJECT_TYPE::CENEMY);


}

void CObjectManager::FixedUpdate()
{
	for (COBJ_MAP::iterator mapiter = m_ObjMap.begin(); mapiter != m_ObjMap.end(); ++mapiter)
	{
		for (COBJ_LIST::iterator iter = mapiter->second.begin(); iter != mapiter->second.end(); ++iter)
		{
			if ((*iter)->Get_BoolIsCollision())
			{
 				iter = mapiter->second.erase(iter);

			}
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
