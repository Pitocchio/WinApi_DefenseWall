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

public: // LifeTime

	double Get_curTime_Life() { return curTime_Life; }
	void Set_curTime_Life(double t) { curTime_Life = t; }
	bool Get_IsDeadbyTime() { return IsDeadbyTime; }
	void Set_IsDeadbyTime(bool b) { IsDeadbyTime = b; }

private: // Variables
	float m_Radius;
	float m_Distance;


	// Memory Release
	double curTime_Life = 0.0f;
	bool IsDeadbyTime;
};

