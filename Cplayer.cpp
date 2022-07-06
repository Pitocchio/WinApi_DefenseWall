#include "stdfx.h"
#include "CPlayer.h"
#include "CBullet.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(Vector2 pos, float radius, float gundistance)
	:CObject(pos)
{
	m_LookVec = { 0, -1 };
	m_Radius = radius;
	m_Angle = 90.0f;
}

void CPlayer::Init()
{
}

void CPlayer::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if (m_Angle < 180)
		{
			m_Angle += 3.0f;
			Set_Lookvec();
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (m_Angle > 0)
		{
			m_Angle -= 3.0f;
			Set_Lookvec();
		}
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		// 총알 생성 & 발사
		Vector2 tempPos = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();
		tempPos = (m_LookVec * 2 * m_Radius) + tempPos;

		CBullet* tempCBullet = new CBullet(tempPos, m_LookVec, CBULLET_RADIUS, CBULLET_DISTANCE);

		CObjectManager::Get_Instance()->Add_CObject(OBJECT_TYPE::CBULLET, tempCBullet);

		//cout << "발사!\n";
	}

}

void CPlayer::LateUpdate()
{
}

void CPlayer::Render(HDC hdc)
{

	// Body
	Vector2 tempPos = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();
	Ellipse(hdc, (int)(tempPos.x - m_Radius), (int)(tempPos.y - (m_Radius)),
		(int)(tempPos.x + m_Radius), (int)(tempPos.y + m_Radius));

	// Gun
	Vector2 center = (m_LookVec * m_Radius) + tempPos;
	MoveToEx(hdc, center.x, center.y, NULL);

	Vector2 center2 = (m_LookVec * 2 * m_Radius) + tempPos;
	LineTo(hdc, center2.x, 
		center2.y);
	

	/*
	
	단위벡터는 단위원 중심 (윈도우의 (0,0))원점을 중심으로 생각

	단위벡터를 만들어두고, 필요한 연산을 위해 적절한 포지션 값을 더해주거나 빼주워서 사용 

	위에 Vector2 center = (m_LookVec * m_Radius) + tempPos; 는

	단위벡터에 길이를 곱해주고, 그 값을 내가 사용하기위한 포지션으로 옮겨준 것이다.
	
	*/

}

void CPlayer::Set_Lookvec()
{
	Vector2 tempVec = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();

	m_LookVec.x = cosf(DEGREETORADIAN(m_Angle));

	m_LookVec.y = -1 * sinf(DEGREETORADIAN(m_Angle));
}

float CPlayer::Get_Radius()
{
	return m_Radius;
}

