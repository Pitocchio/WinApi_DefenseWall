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

오브젝트매니저에서 오브젝트 맵을 가져와 돌리며
오브젝트에서 컴포넌트 맵을 가져와 find로 콜라이더를 끄집어 낸다!


Collision case 1
	Bullet, Enemy, CIRCLE2D, BOX2D

Collision case 2
	Enemy, Brick. BOX2D, BOX2D

*/