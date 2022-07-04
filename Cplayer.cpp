#include "stdfx.h"
#include "CPlayer.h"



CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(Vector2 pos)
{
	
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
	//Ellipse(hdc, Get_Pos().x - m_Radius, Get_Pos().y - m_Radius, Get_Pos().x + m_Radius, Get_Pos().y + m_Radius);

	float tempRadius = this->Get_Radius();
	Vector2 tempPos = this->Get_Transform();

	Ellipse(hdc, tempPos.x - tempRadius, tempPos.y - tempRadius,
		tempPos.x + tempRadius, tempPos.y - tempRadius);

}

float CPlayer::Get_Radius()
{
	return m_Radius;
}
