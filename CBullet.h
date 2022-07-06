#pragma once
#include "CObject.h"

class CBullet : public CObject
{
public:
	CBullet();
	~CBullet();
	CBullet(Vector2 pos, Vector2 m_LookVec, float radius, float distance);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

public:
	float Get_Radius() { return m_Radius; }


private: // Variables
	float m_Radius;
	float m_Distance;
};

