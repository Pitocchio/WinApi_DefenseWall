#pragma once
#include "CObject.h"

class CEnemy : public CObject
{
public:
	CEnemy();
	~CEnemy();
	CEnemy(Vector2 pos, float radius, float distance);


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

