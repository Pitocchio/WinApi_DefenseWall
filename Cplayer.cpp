#include "stdfx.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(Vector2 pos, float radius)
	:CObject(pos)
{
	m_Radius = radius;
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
	float tempRadius = Get_Radius();
	Vector2 tempPos = Get_Transform(); // ���⿡�� �޾ƿ����� ����

	Ellipse(hdc, (int)(tempPos.x - tempRadius), (int)(tempPos.y - tempRadius),
		(int)(tempPos.x + tempRadius), (int)(tempPos.y - tempRadius));
}

float CPlayer::Get_Radius()
{
	return m_Radius;
}
