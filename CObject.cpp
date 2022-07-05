#include "stdfx.h"
#include "CObject.h"
#include "Transform.h"

CObject::CObject()
{
	m_Angle = 0;
	m_LookVec = m_LookVec.Normalize();
}

CObject::~CObject()
{
}

CObject::CObject(Vector2 pos)
{
	Transform* tempTransform = new Transform(pos); 

	Add_Component(Component::COMPONENT_TYPE::TRANSFORM, tempTransform);
	// 생성과 동시에 컴포넌트-트랜스폼 추가
}

void CObject::Update()
{

}

void CObject::Plus_Angle()
{
	if (m_Angle < 180)
		m_Angle += 0.1f;
}

void CObject::Minus_Angle()
{
	if (m_Angle > 0) 
		m_Angle -= 0.1f; 
}

void CObject::Set_Lookvec()
{

}

void CObject::Add_Component(Component::COMPONENT_TYPE type, Component*temp)
{
	if (temp == nullptr)
		return;

	COMPONENT_MAP::iterator iter = m_CpnMap.find(type);

	if (iter == m_CpnMap.end())
	{
		m_CpnMap.insert({ type, temp });
		return;
	}
}
