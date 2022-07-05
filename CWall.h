#pragma once
#include "CObject.h"

class CWall : public CObject
{

public :
	CWall();
	~CWall();
	CWall(Vector2 pos);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

public : // Set
	void Subtract_Strength() { m_iStrength--; }

private: // Variables
	int m_iStrength;
};

