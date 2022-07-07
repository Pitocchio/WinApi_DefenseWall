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
	IsDeadbyTime = false;
}

void CBullet::Init()
{

}

void CBullet::Update()
{
	/* LIFETIME UPDATE*/
	curTime_Life += CTimeManager::Get_Instance()->Get_Deltatime();

	if (curTime_Life >= COBJECT_LIFETIME)
	{
		IsDeadbyTime = true;
		curTime_Life = 0.0f; // 근데 어차피 이 객체는 사라질건데 초기화가 굳이 필요?
	}




	/* POSITION UPDATE */
	Vector2 tempPos = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();

	tempPos.x += (m_LookVec.x * m_Distance) * CTimeManager::Get_Instance()->Get_Deltatime();
	tempPos.y += (m_LookVec.y * m_Distance) * CTimeManager::Get_Instance()->Get_Deltatime();

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

