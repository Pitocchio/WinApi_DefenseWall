#include "stdfx.h"
#include "CBullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

CBullet::CBullet(Vector2 pos, Vector2 m_LookVec, float radius, float distance)
	:CObject(pos, m_LookVec)
{
	m_Radius = radius;
	m_Angle = 90.0f;
	m_Distance = distance;
}

void CBullet::Init()
{

}

void CBullet::Update()
{
	/* POSITION UPDATE */

	Vector2 tempPos = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();

	tempPos.x += (m_LookVec.x * m_Distance);
	tempPos.y += (m_LookVec.y * m_Distance);

	dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Set_VecPos(tempPos);

}

void CBullet::LateUpdate()
{
}

void CBullet::Render(HDC hdc)
{
	Vector2 tempPos = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();

	Ellipse(hdc, (int)(tempPos.x - m_Radius), (int)(tempPos.y - (m_Radius)),
		(int)(tempPos.x + m_Radius), (int)(tempPos.y + m_Radius));
}

