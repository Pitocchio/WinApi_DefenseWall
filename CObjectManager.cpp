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

	CTimeManager::Get_Instance()->Update(); // 타임 매니저 업데이트

	/* CEnemy 생성 - TimeManager */
	curTime += CTimeManager::Get_Instance()->Get_Deltatime();
	if (curTime >= CENEMY_CREATE_DELAYTIME)
	{
		//Vector2 tempCEnemyVec = { rand() % (WINDOW_WIDTH - 160) + 160, CENEMY_START_POS_Y };
		Vector2 tempCEnemyVec = { (rand() % 8) * 160 + 80, CENEMY_START_POS_Y };
		CEnemy* tempCEnemy = new CEnemy(tempCEnemyVec, CENEMY_RADIUS, CENEMY_DISTANCE);
		CObjectManager::Get_Instance()->Add_CObject(OBJECT_TYPE::CENEMY, tempCEnemy);
		cout << tempCEnemyVec.x << "\n";
		curTime = 0.0f; // 다시 시간 초기화
	}

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
	// 충돌 체크 (이후 최적화+수정 필요)
	CollisionMnager::Get_Instance()->Check_Collision(CollisionMnager::COLLISION_TYPE::CIRCLE2D, OBJECT_TYPE::CBULLET, OBJECT_TYPE::CENEMY);
	CollisionMnager::Get_Instance()->Check_Collision2(CollisionMnager::COLLISION_TYPE::BOX2D, OBJECT_TYPE::CENEMY, OBJECT_TYPE::CWALL);

}

void CObjectManager::FixedUpdate()
{
	// Map erase 주의사항! for문에서 ++iter가 아니라, else문 따로 만들어서 iter++ 해줘야함!!
	
	// 충돌 처리
	for (COBJ_MAP::iterator mapiter = m_ObjMap.begin(); mapiter != m_ObjMap.end(); ++mapiter)
	{
		for (COBJ_LIST::iterator iter = mapiter->second.begin(); iter != mapiter->second.end();)
		{
			if ((*iter)->Get_BoolIsCollision())
			{
 				iter = mapiter->second.erase(iter);
			}
			else
			{
				iter++;
			}
			
		}
	}

	// 사망 처리 (라이프타임 초과 = CBullet, CEnemy)
	// wstring으로 유지 보수 쉽게 만들게끔 해야함
	for (COBJ_MAP::iterator mapiter = m_ObjMap.begin(); mapiter != m_ObjMap.end(); ++mapiter)
	{
		if (mapiter->first == OBJECT_TYPE::CBULLET)
		{
			for (COBJ_LIST::iterator iter = mapiter->second.begin(); iter != mapiter->second.end();)
			{
				if (dynamic_cast<CBullet*>(*iter)->Get_IsDeadbyTime())
				{
					iter = mapiter->second.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}
		if (mapiter->first == OBJECT_TYPE::CENEMY)
		{
			for (COBJ_LIST::iterator iter = mapiter->second.begin(); iter != mapiter->second.end();)
			{
				if (dynamic_cast<CEnemy*>(*iter)->Get_IsDeadbyTime())
				{
					iter = mapiter->second.erase(iter);
				}
				else
				{
					iter++;
				}
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
