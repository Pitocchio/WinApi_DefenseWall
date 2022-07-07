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

void CollisionMnager::Check_Collision(COLLISION_TYPE coltype, OBJECT_TYPE objtype1, OBJECT_TYPE objtype2)
{
	/*
	 �Ű����� : obj1�� obj2�� ���� �ݶ��̴��� ���� �־�� �ϰ�, coltype�� �ݶ��̴��� �ȴ�

	 �ݸ���Ÿ���� ���� ����ġ (���Ǿ�� �ڽ��� aabb��)
	 �׸��� ���Ǿ��� ��Ʈ�� ����
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
	*/

	COBJ_MAP OBjMaptemp = CObjectManager::Get_Instance()->Get_ObjectMap();

	/* OBJ1 */
	for (COBJ_MAP::iterator OBJ1_Mapiter = OBjMaptemp.begin(); OBJ1_Mapiter != OBjMaptemp.end(); ++OBJ1_Mapiter)
	{
		if (OBJ1_Mapiter->first == objtype1)
		{
			for (COBJ_LIST::iterator OBJ1_iter = OBJ1_Mapiter->second.begin(); OBJ1_iter != OBJ1_Mapiter->second.end(); ++OBJ1_iter)
			{
				Vector2 obj1_Pos = dynamic_cast<Transform*>((*OBJ1_iter)->Get_ComponentMap().begin()->second)->Get_VecPos();
				float obj1_Rad = dynamic_cast<CBullet*>(*OBJ1_iter)->Get_Radius();

				/* OBJ2 */
				for (COBJ_MAP::iterator OBJ2_Mapiter = OBjMaptemp.begin(); OBJ2_Mapiter != OBjMaptemp.end(); ++OBJ2_Mapiter)
				{
					if (OBJ2_Mapiter->first == objtype2)
					{
						for (COBJ_LIST::iterator OBJ2_iter = OBJ2_Mapiter->second.begin(); OBJ2_iter != OBJ2_Mapiter->second.end(); ++OBJ2_iter)
						{
							Vector2 obj2_Pos = dynamic_cast<Transform*>((*OBJ2_iter)->Get_ComponentMap().begin()->second)->Get_VecPos();
							float obj2_Rad = dynamic_cast<CEnemy*>(*OBJ2_iter)->Get_Radius();

							if (obj1_Rad + obj2_Rad >
								sqrt(pow(obj1_Pos.x - obj2_Pos.x, 2) + pow(obj1_Pos.y - obj2_Pos.y, 2)))
							{
								(*OBJ1_iter)->Set_BoolIsCollision(true);
								(*OBJ2_iter)->Set_BoolIsCollision(true);								
							}
						}
					}
				}
			}
		}
	}
}

void CollisionMnager::Check_Collision2(COLLISION_TYPE coltype, OBJECT_TYPE objtype1, OBJECT_TYPE objtype2)
{
	COBJ_MAP OBjMaptemp = CObjectManager::Get_Instance()->Get_ObjectMap();

	/* OBJ1 */ // Enemy
	for (COBJ_MAP::iterator OBJ1_Mapiter = OBjMaptemp.begin(); OBJ1_Mapiter != OBjMaptemp.end(); ++OBJ1_Mapiter)
	{
		if (OBJ1_Mapiter->first == objtype1)
		{
			for (COBJ_LIST::iterator OBJ1_iter = OBJ1_Mapiter->second.begin(); OBJ1_iter != OBJ1_Mapiter->second.end(); ++OBJ1_iter)
			{
				Vector2 obj1_Pos = dynamic_cast<Transform*>((*OBJ1_iter)->Get_ComponentMap().begin()->second)->Get_VecPos();
				float obj1_Rad = dynamic_cast<CEnemy*>(*OBJ1_iter)->Get_Radius();

				/* OBJ2 */ // Wall
				for (COBJ_MAP::iterator OBJ2_Mapiter = OBjMaptemp.begin(); OBJ2_Mapiter != OBjMaptemp.end(); ++OBJ2_Mapiter)
				{
					if (OBJ2_Mapiter->first == objtype2)
					{
						for (COBJ_LIST::iterator OBJ2_iter = OBJ2_Mapiter->second.begin(); OBJ2_iter != OBJ2_Mapiter->second.end(); ++OBJ2_iter)
						{
							Vector2 obj2_Pos = dynamic_cast<Transform*>((*OBJ2_iter)->Get_ComponentMap().begin()->second)->Get_VecPos();

							// ���⼭ �浹 üũ
							if (obj1_Rad + CWALL_HEIGHT >
								sqrt(pow(obj1_Pos.x - obj2_Pos.x, 2) + pow(obj1_Pos.y - obj2_Pos.y, 2)))
							{
								(*OBJ1_iter)->Set_BoolIsCollision(true);
								(*OBJ2_iter)->Set_BoolIsCollision(true);
							}
						}
					}
				}
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