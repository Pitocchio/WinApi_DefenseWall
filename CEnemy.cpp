#include "stdfx.h"
#include "CEnemy.h"

CEnemy::CEnemy()
{
}

CEnemy::~CEnemy()
{
}

CEnemy::CEnemy(Vector2 pos, float radius, float distance)
	:CObject(pos)
{
	m_LookVec = { 0, 1 };
	m_Radius = radius;
	m_Distance = distance;
}

void CEnemy::Init()
{
}

void CEnemy::Update()
{
	/* POSITION UPDATE */

	Vector2 tempPos = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();

	tempPos.x += (m_LookVec.x * m_Distance);
	tempPos.y += (m_LookVec.y * m_Distance);

	dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Set_VecPos(tempPos);
}

void CEnemy::LateUpdate()
{
}

void CEnemy::Render(HDC hdc)
{
	Vector2 tempPos = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();

	Ellipse(hdc, (int)(tempPos.x - m_Radius), (int)(tempPos.y - (m_Radius)),
		(int)(tempPos.x + m_Radius), (int)(tempPos.y + m_Radius));
}
