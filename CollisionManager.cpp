#include "stdfx.h"
#include "CObjectManager.h"

CollisionMnager* CollisionMnager::m_ColMgr = nullptr;

CollisionMnager::CollisionMnager()
{
}

CollisionMnager::~CollisionMnager()
{
}

CollisionMnager* CollisionMnager::Get_Instance()
{
	if (!m_ColMgr)
		m_ColMgr = new CollisionMnager;
	return m_ColMgr;
}

void CollisionMnager::Destroy_Instance()
{
	delete m_ColMgr;

}

void CollisionMnager::Check_Collision(COLLISION_TYPE coltype, CObjectManager::OBJECT_TYPE objtype1, CObjectManager::OBJECT_TYPE objtype2)
{
	// 매개변수 : obj1과 obj2는 같은 콜라이더를 갖고 있어야 하고, coltype이 콜라이더가 된다

	// 콜리전타입을 갖고 스위치 (스피어냐 박스냐 aabb냐)
	// 그리고 스피어라면 스트링 세팅
	wstring ColliderName;
	switch (coltype)
	{
	case COLLISION_TYPE::CIRCLE2D:
	{
		ColliderName = L"CircleCollider2D";
		break;
	}

	case COLLISION_TYPE::BOX2D:
	{
		ColliderName = L"BoxCollider2D";
		break;
	}

	case COLLISION_TYPE::AABB:
	{
		ColliderName = L"AABBColider2D";
		break;
	}
	}

	COBJ_MAP OBjMaptemp = CObjectManager::Get_Instance()->Get_ObjectMap();

	// 콜라이더를 갖고온다. 겟컴포넌트
	// 갖고 온 컴포넌트를 위 스트링으로 체크
	// 해당하지 않는다면 continue
	// 해당한다면 충돌처리


	if (ColliderName == L"CircleCollider2D")
	{

		for (COBJ_MAP::iterator iterObj1 = OBjMaptemp.begin(); iterObj1 != OBjMaptemp.end(); ++iterObj1)
		{
			if (iterObj1->first == objtype1)
			{

			}
		}
	}
	


}

//https://blog.naver.com/36513535/10024329388

/*

오브젝트매니저에서 오브젝트 맵을 가져와 돌리며
오브젝트에서 컴포넌트 맵을 가져와 find로 콜라이더를 끄집어 낸다!


Collision case 1
	Bullet, Enemy / CIRCLE2D, BOX2D

Collision case 2
	Enemy, Brick / BOX2D, BOX2D

*/