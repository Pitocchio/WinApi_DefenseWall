#include "stdfx.h"
#include "CWall.h"

CWall::CWall()
{
}

CWall::~CWall()
{
}

CWall::CWall(Vector2 pos)
	: CObject(pos)
{
	m_iStrength = 3;

}

void CWall::Init()
{
}

void CWall::Update()
{
}

void CWall::LateUpdate()
{
}

void CWall::Render(HDC hdc)
{
	Vector2 tempPos = dynamic_cast<Transform*>(m_CpnMap.begin()->second)->Get_VecPos();
	Rectangle(hdc, (int)(tempPos.x - (CWALL_WIDTH/2)), (int)(tempPos.y - (CWALL_HEIGHT * 2)),
		(int)(tempPos.x + (CWALL_WIDTH / 2)), (int)(tempPos.y));

}
