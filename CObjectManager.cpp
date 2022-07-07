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
	/* CPlayer ���� */
	Vector2 tempCPlayerVec = { CPLAYER_START_POS_X, CPLAYER_START_POS_Y };
	CPlayer* tempCPlayer = new CPlayer(tempCPlayerVec, CPLAYER_RADIUS, CPLAYER_GUN_DISTANCE);
	Add_CObject(OBJECT_TYPE::CPLAYER, tempCPlayer);


	/* CWall ���� */
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

	CTimeManager::Get_Instance()->Update(); // Ÿ�� �Ŵ��� ������Ʈ

	/* CEnemy ���� - TimeManager */
	curTime += CTimeManager::Get_Instance()->Get_Deltatime();
	if (curTime >= CENEMY_CREATE_DELAYTIME)
	{
		//Vector2 tempCEnemyVec = { rand() % (WINDOW_WIDTH - 160) + 160, CENEMY_START_POS_Y };
		Vector2 tempCEnemyVec = { (rand() % 8) * 160 + 80, CENEMY_START_POS_Y };
		CEnemy* tempCEnemy = new CEnemy(tempCEnemyVec, CENEMY_RADIUS, CENEMY_DISTANCE);
		CObjectManager::Get_Instance()->Add_CObject(OBJECT_TYPE::CENEMY, tempCEnemy);
		cout << tempCEnemyVec.x << "\n";
		curTime = 0.0f; // �ٽ� �ð� �ʱ�ȭ
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
	// �浹 üũ (���� ����ȭ+���� �ʿ�)
	CollisionMnager::Get_Instance()->Check_Collision(CollisionMnager::COLLISION_TYPE::CIRCLE2D, OBJECT_TYPE::CBULLET, OBJECT_TYPE::CENEMY);
	CollisionMnager::Get_Instance()->Check_Collision2(CollisionMnager::COLLISION_TYPE::BOX2D, OBJECT_TYPE::CENEMY, OBJECT_TYPE::CWALL);

}

void CObjectManager::FixedUpdate()
{
	// Map erase ���ǻ���! for������ ++iter�� �ƴ϶�, else�� ���� ���� iter++ �������!!
	
	// �浹 ó��
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

	// ��� ó�� (������Ÿ�� �ʰ� = CBullet, CEnemy)
	// wstring���� ���� ���� ���� ����Բ� �ؾ���
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
