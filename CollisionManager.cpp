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
	// �Ű����� : obj1�� obj2�� ���� �ݶ��̴��� ���� �־�� �ϰ�, coltype�� �ݶ��̴��� �ȴ�

	// �ݸ���Ÿ���� ���� ����ġ (���Ǿ�� �ڽ��� aabb��)
	// �׸��� ���Ǿ��� ��Ʈ�� ����
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

	// �ݶ��̴��� ����´�. ��������Ʈ
	// ���� �� ������Ʈ�� �� ��Ʈ������ üũ
	// �ش����� �ʴ´ٸ� continue
	// �ش��Ѵٸ� �浹ó��


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

������Ʈ�Ŵ������� ������Ʈ ���� ������ ������
������Ʈ���� ������Ʈ ���� ������ find�� �ݶ��̴��� ������ ����!


Collision case 1
	Bullet, Enemy / CIRCLE2D, BOX2D

Collision case 2
	Enemy, Brick / BOX2D, BOX2D

*/