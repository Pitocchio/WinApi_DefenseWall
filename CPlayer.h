#pragma once
#include "CObject.h"

class CPlayer : public CObject
{

public:
	CPlayer();
	~CPlayer();
	CPlayer(Vector2 pos, float radius, float gundistance);


public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

public:
	virtual void Set_Lookvec() override;

public: // Get
	float Get_Radius();

private: // Variables
	float m_Radius;
	float m_Distance;
};