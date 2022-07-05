#include "stdfx.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(Vector2 pos, float radius, float gundistance)
	:CObject(pos)
{
	m_Radius = radius;
	m_Angle = 90.0f;
}

void CPlayer::Init()
{
}

void CPlayer::Update()
{
}

void CPlayer::LateUpdate()
{
}

void CPlayer::Render(HDC hdc)
{

	// Body
	Vector2 tempPos = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();
	Ellipse(hdc, (int)(tempPos.x - m_Radius), (int)(tempPos.y - (m_Radius*2)),
		(int)(tempPos.x + m_Radius), (int)(tempPos.y));

	// Gun
	MoveToEx(hdc, tempPos.x, tempPos.y - (m_Radius * 2), NULL);
	LineTo(hdc, tempPos.x, tempPos.y - (m_Radius * 2) - CPLAYER_GUN_DISTANCE);

}

void CPlayer::Set_Lookvec()
{
	
	Vector2 tempVec = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();

	m_LookVec.x += cosf(m_Angle) * tempVec.Normalize().x;
	m_LookVec.y += -sinf(m_Angle) * tempVec.Normalize().y;
	
}

float CPlayer::Get_Radius()
{
	return m_Radius;
}


/*

- MoveToEx(HDC ,int X , int Y , NULL);  - Ŀ�� ���� ���� ���� , NULL�� ����ü�� ���� ��ġ���� �޾ƿ��°�(�̻��)

- LineTo( HDC , int X , int Y );               - ���� , ���� ��ġ�� ���� (X,Y) �� �̵�.
*/