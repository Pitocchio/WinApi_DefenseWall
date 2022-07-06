#include "stdfx.h"
#include "CObject.h"
#include "Transform.h"

CObject::CObject()
{
	
}

CObject::~CObject()
{
}

CObject::CObject(Vector2 pos)
{
	bIsCollision = false;
	m_Angle = 90.0f;

	Transform* tempTransform = new Transform(pos); 
	Add_Component(Component::COMPONENT_TYPE::TRANSFORM, tempTransform);

	m_LookVec.Normalize();
}

CObject::CObject(Vector2 pos, Vector2 Lookvec)
{
	m_Angle = 90.0f;

	Transform* tempTransform = new Transform(pos);
	Add_Component(Component::COMPONENT_TYPE::TRANSFORM, tempTransform);

	m_LookVec = Lookvec;
}


void CObject::Update()
{

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
