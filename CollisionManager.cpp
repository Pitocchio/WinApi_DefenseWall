#include "CollisionManager.h"

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

void CollisionMnager::CheckCollision(wstring objtype1, wstring objtype2, wstring coltype1, wstring coltype2)
{

}




/*

������Ʈ�Ŵ������� ������Ʈ ���� ������ ������
������Ʈ���� ������Ʈ ���� ������ find�� �ݶ��̴��� ������ ����!


Collision case 1
	Bullet, Enemy, CIRCLE2D, BOX2D

Collision case 2
	Enemy, Brick. BOX2D, BOX2D

*/