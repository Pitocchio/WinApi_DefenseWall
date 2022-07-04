#include "stdfx.h"
#include "CObject.h"
#include "Transform.h"

CObject::CObject()
{
	m_Angle = 0;
	m_UnitVec = m_UnitVec.Normalize();
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
